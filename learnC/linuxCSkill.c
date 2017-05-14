#include <stdio.h>
#include <stdlib.h>

/*
 *Linux C 面向对象的实现：
 *封装：数据和对数据的操作分开。参考struct file;
 *继承：抽象出共性形成基类，子类添加自己的特性。参考strut list_head;
 *多态：通过共同的接口，实现对不同实现体的调用。通过container_of宏实现基类指针到具体子类指针的转换。
 */

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
 *Linux 双向链表
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
	//初始化双向链表
	LIST_HEAD(person_head);
	//向链表添加节点	
	for(int i = 0; i < 5; ++i)
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
	int a = ({1;2;3;});
	printf("({1;2;3}): %d\n", a);
	return 0;
}
