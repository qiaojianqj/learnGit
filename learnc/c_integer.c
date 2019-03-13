#include <stdio.h>

int main() {
	/*
	 * 带符号数，机器码：1 111 .... 1111
	 */
	int x = -1; 

	/*
	 * 无符号数，机器码：1000 .... 0000
	 */
	unsigned u = 2147483648; 

	/*
	%u表示以无符号数来解析：1 111 .... 1111 = 2^32 - 1 = 4294967295
	%d表示以带符号数来解析：1 111 .... 1111 = -1
	*/
	printf("x = %u = %d\n", x, x);

	/*	
	%u表示以无符号数来解析：1000 .... 0000 = 2^31 = 2147483648
	%d表示以带符号数来解析：1000 .... 0000 = 模32表示的最大负数: -2^31
	*/
	printf("u = %u = %d\n", u, u);

	return 0;
}