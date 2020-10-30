#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *Linux C 面向对象的实现：
 *封装：数据和对数据的操作分开。参考struct file;
 *继承：抽象出共性形成基类，子类添加自己的特性。参考strut list_head;
 *多态：通过共同的接口，实现对不同实现体的调用。通过container_of宏实现基类指针到具体子类指针的转换。
 */

/*
 *Linux C 结构体成员－零长度数组
 *作用：为结构体内的数据分配一个连续的内存，方便内存释放，提高访问速度，减少内存碎片
 *结构体中的零长度数组成员不占结构体size，仅是个占位标示符
 *直到为结构体分配了内存后，这个占位标示符才成为一个有长度的数组
 */
struct line{
	int length;
	char contents[]; //同char contents[0];
};

/*
 *数组名作为函数形参后，数组名变成一个普通指针
 */
void arrayTest(char str[])
{
	 printf("sizeof str:%d\n",sizeof(str));
	 printf("str:%s\n",str);
	 str++;
	 printf("after str++:%s\n",str);
	 str = "now str point to here";
	 printf("after modify str:%s\n",str);

}

/*
 *一种定义函数指针的方法
 *这种定义方法有一个优势就是，即使你没有看到read_proc_t的定义，也能够清楚的知道proc_read是一个指针
 */
typedef int (read_proc_t)(char *page, char **start, size_t offset, int count, int *eof, void *data);
read_proc_t *proc_read;

/*
 *offsetof宏的巧妙之处在于将地址0强制转换为type类型的指针，从而定位到member在结构体中偏移位置。编译器认为0是一个有效的地址，从而认为0是type指针的起始地址
 */
#define offsetof(type, member) (size_t)&(((type*)0)->member)

/*
 *container_of宏分为两部分，
 * 
 *第一部分：const typeof( ((type *)0)->member ) *__mptr = (ptr);
 *通过typeof定义一个member指针类型的指针变量__mptr，（即__mptr是指向member类型的指针），并将__mptr赋值为ptr。
 * 
 *第二部分： (type *)( (char *)__mptr - offsetof(type,member) );
 *通过offsetof宏计算出member在type中的偏移，然后用member的实际地址__mptr减去偏移，得到type的起始地址，即指向type类型的指针
 */
#define container_of(ptr, type, member) ({ \
	const typeof( ((type *)0)->member ) *__mptr = (ptr); \
	(type *)( (char *)__mptr - offsetof(type,member) );})    

/*
 *Linux hash链表
 *散列表的目的是为了方便快速的查找，所以散列表通常是一个比较大的数组，否则“冲突”的概率会非常大，这样就失去了散列表的意义。如何来做到既能维护一张大表，又能不占用过多的内存呢?此时对于哈希表的每个entry(表头结点)它的结构体中只能存放一个指针。这样做的话可以节省一半的指针空间，尤其是在hash bucket很大的情况下。（如果有两个指针域将占用8个字节空间）
 *
 *hlist的结点有两个指针，但是pprev是指针的指针，它指向的是前一个结点的next指针，为什么要采用pprev，而不采用一级指针？
 *1> 为了能统一地修改表头的first指针:通过一致的pprev指针访问和修改前结点的next（或first）指针
 *2> 解决了数据结构不一致:hlist_head和hlist_node不一致，但是hlist_head和hlist_node指向的下一个节点的指针类型相同
 *                |------|     |------|           |------|
 *  |-------|     | data |     | data |           | data |
 *  |       |     |------|     |------|           |------|
 *  |       |	  | node |     | node |           | node |
 *  |-------|     |------|     |------|  ... ...  |------|
 * 	| first |---->| next |---->| next |--->   --->| next |---> NULL
 *  |-------|     |------|     |------|           |------|
 * 	|       |<----| pprev|<----| pprev|<---   <---| pprev|
 *	|-------|     |------|     |------|           |------|
 *  HashTable
 * /
struct hlist_head {
		struct hlist_node *first;
};

struct hlist_node {
		struct hlist_node *next, **pprev;
};

/*
 *Linux 双向链表
 *                |------|     |------|           |------|
 *  			  | data |     | data |           | data |
 *                |------|     |------|           |------|
 *     head       | node |     | node |           | node |
 *   |------|     |------|     |------|  ... ...  |------|
 * 	 | prev |<----| prev |<----| prev |<---   <---| prev |
 *   |------|     |------|     |------|           |------|
 * 	 | next |---->| next |---->| next |--->   --->| next |
 *	 |------|     |------|     |------|           |------|
 *
 */
struct list_head {
	struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

//用static inline修饰函数定义，使得将函数编译成宏替换
static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

#define __list_for_each(pos, head) \
	for (pos = (head)->next; pos != (head); pos = pos->next)

struct Person{
	char name[20];
	int age;
	struct list_head list;
};

int main()
{
	struct Person *pPerson = NULL;
	struct list_head *p;
	int i;
	//初始化双向链表
	LIST_HEAD(person_head);
	//向链表添加节点	
	for(i = 0; i < 5; ++i)
	{
		pPerson = (struct Person *)malloc(sizeof(struct Person));	
		sprintf(pPerson->name, "%s%d", "Person", i+1);
		pPerson->age = (i+1)*10;
		//list_add(&(pPerson->list), &person_head);
		list_add_tail(&(pPerson->list), &person_head);
	}
	//遍历链表
	printf("---1st iterator list---\n");
	__list_for_each(p, &person_head)
	{
		pPerson = list_entry(p, struct Person, list);
		printf("name:%s, age:%d\n", pPerson->name, pPerson->age);
	}
	//删除节点
	printf("---delete list node---\n");
	__list_for_each(p, &person_head)
	{
		pPerson = list_entry(p, struct Person, list);
		if(pPerson->age == 20)
		{
			printf("delete name:%s, age:%d\n",pPerson->name, pPerson->age);
			list_del(p);
			free(pPerson);
		}
	}	
	//再次遍历链表
	printf("---2st iterator list---\n");
	__list_for_each(p, &person_head)
	{
		pPerson = list_entry(p, struct Person, list);
		printf("name:%s, age:%d\n", pPerson->name, pPerson->age);
	}
	//释放链表节点资源
	__list_for_each(p, &person_head)
	{
		pPerson = list_entry(p, struct Person, list);
		list_del(p);
		free(pPerson);
	}

	//表达式({A;B;C;})返回的值是C的值
	int j = ({1;2;3;});
	printf("({1;2;3}): %d\n", j);

	//结构体的零长度数组成员(最后个成员)
	int this_length = 10;
	printf("sizeof line: %d\n", sizeof(struct line));
	struct line *thisline = (struct line *)malloc(sizeof(struct line) + this_length);
	thisline->length = this_length;
    strcpy(thisline->contents, "balabala");	
	free(thisline);

	//数组int a[5]
	//数组名的内涵：指代数组
	//数组名a可看作一个指向int型的常量指针
	//在以下三中场合下，数组名并不是用常量指针来表示，就是数组名作为sizeof操作符/单目操作符&的操作数以及作为函数形参时。 
	//1. sizeof返回整个数组的长度，而不是指向数组的指针的长度。 
	//2. 取一个数组名的地址(&a)所产生的是一个指向数组的指针，而不是一个指向某个常量指针的指针。
	//3. 数组名作为函数形参时，其全面沦落为一个普通指针，不再具有常量性，可自增自减可修改。
	int a[5] = {0};
	printf("%x\n", a);
	printf("%x\n", a+1);
	printf("%x\n", &a);
	printf("%x\n", &a+1);
	printf("sizeof a: %x\n", sizeof(a));
	/*
	(gdb) p a
		$2 = {0, 0, 0, 0, 0}
	(gdb) p a+1
		$3 = (int *) 0x7fff5fbffb64
		(gdb) p &a
		$4 = (int (*)[5]) 0x7fff5fbffb60
		(gdb) p &a+1
		$5 = (int (*)[5]) 0x7fff5fbffb74
	*/
	char str1[20] = "I Love fuck U";
	arrayTest(str1);

	return 0;
}
