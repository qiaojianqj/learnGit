#include <stdio.h>

int global; //bss section
int global1 = 1; //data section
static int global_static; //bss section
static int global_static1 = 1; //data section
/*
 * 如何给结构体变量分配空间由编译器决定
 * 
 * linux gcc编译器在编译程序时会遵循两条原则：
 * 一、结构体变量中成员的偏移量必须是成员大小的整数倍（0被认为是任何数的整数倍) 
 * 二、结构体大小必须是所有成员大小的整数倍(公倍数)
 *
 * 如果结构体中的成员又是另外一种结构体类型时应该怎么计算呢？只需把其展开即可。
 * 但有一点需要注意，展开后的结构体的第一个成员的偏移量应当是被展开的结构体中最大的成员的整数倍
 */
typedef struct global_struct{
	short a;
	int b;
	char c;
}GlobalStruct; 

typedef struct global_struct1{
	char a;
	int b;
	short c;
}GlobalStruct1; 

typedef struct global_struct2{
	char a;
	short b;
	int c;
}GlobalStruct2; 

typedef struct global_struct3
{
	short i;
	struct 
	{
		char c;
		int j;
	} ss; 
	int k;
}GlobalStruct3;

int main(int argc, char *argv[])
{
	static int local_static; //bss section
	static int local_static1 = 1; //data section

	int local_stack; //stack section

	printf("address of bss: %p\n", &global);
	printf("address of data: %p\n", &global1);
	printf("address of stack: %p\n", &local_stack);

	int *pInt = malloc(sizeof(int));
	printf("address of stack: %p\n", &pInt);
	printf("address of heap: %p\n", pInt);

	printf("sizeof short: %d\n", sizeof(short));
	printf("sizeof int: %d\n", sizeof(int));
	printf("sizeof char: %d\n", sizeof(char));
	printf("sizeof float: %d\n", sizeof(float));
	printf("sizeof double: %d\n", sizeof(double));

	printf("sizeof struct: %d\n", sizeof(GlobalStruct));
	printf("sizeof struct1: %d\n", sizeof(GlobalStruct1));
	printf("sizeof struct2: %d\n", sizeof(GlobalStruct2));
	printf("sizeof struct3: %d\n", sizeof(GlobalStruct3));

	printf("Hello, World!\n");
	return 0;
}
