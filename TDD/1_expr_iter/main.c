/**
 *TDD开发三部军规
 *1. 先写测试用例，编译通过，执行测试用例不通过。
 *2. 快速实现代码，执行测试用例通过。
 *3. 重构优化，去除重复代码，抽象出领域规则。
 */
#include <assert.h>
#include <stdio.h>

extern int expr(const char *str);

int main()
{
	assert(expr("1") == 1);
	assert(expr("2") == 2);
	
	printf("OK!\n");
	return 0;
}
