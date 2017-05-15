#include <stdio.h>
#include <unistd.h>

//
int main()  
{
	//printf返回值是输出的字符个数
	int i = 43;
	printf("%d\n",printf("%d",printf("%d",i)));	

	//switch-case语句会把变量b的初始化直接就跳过了
	int a=1;      
	switch(a)      
	{   
		int b=20;          
	case 1: 
		printf("b is %d\n",b);
		break;
	default:
		printf("b is %d\n",b);
		break;
	}

	//sizeof不是一个函数，是一个操作符，其求i++的类型的size，这是一件可以在程序运行前（编译时）完成的事情
	//所以，sizeof(i++)直接就被4给取代了，在运行时也就不会有了i++这个表达式
	i = 10;
	printf("i : %d\n",i);
	printf("sizeof(i++) is: %d\n",sizeof(i++));
	printf("i : %d\n",i);

	//string = "Hello!", &string[2] = &*(string+2) = &*(2+string) = &2[string]
	//&"Hello!"[2] = &*("Hello!"+2) = &*(2+"Hello!") = &2["Hello!"]
	int b = 5;
	a = 3;
	printf(&a["Ya!Hello! how is this? %s\n"], &b["junk/super"]);

	printf(&*("Ya!Hello! how is this? %s\n" + 3), &*(5 + "junk/super"));

	printf(&"Ya!Hello! how is this? %s\n"[3], &"junk/super"[5]);

	printf("Hello! how is this? %s\n", "super");

	printf(&a["WHAT%c%c%c  %c%c  %c !\n"], 1["this"],
		2["beauty"],0["tool"],0["is"],3["sensitive"],4["CCCCCC"]);

	printf(&*(3+"WHAT%c%c%c  %c%c  %c !\n"), *(1+"this"),
		*(2+"beauty"),*(0+"tool"),*(0+"is"),*(3+"sensitive"),*(4+"CCCCCC"));

	printf(&"WHAT%c%c%c  %c%c  %c !\n"[3], "this"[1],
		"beauty"[2],"tool"[0],"is"[0],"sensitive"[3],"CCCCCC"[4]);

	printf("T%c%c%c  %c%c  %c !\n", 'h',
		'a','t','i','s','C');

	printf("%c\n", 2["thIs"]);
	printf("%s\n",&3["notLove"]);

	return 0;
}
