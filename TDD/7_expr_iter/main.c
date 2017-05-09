/**
 *TDD开发三部军规
 *1. 先写测试用例，编译通过，执行测试用例不通过。
 *2. 快速实现代码，执行测试用例通过。
 *3. 重构优化，去除重复代码，抽象出领域规则。
 */
#include <assert.h>
#include <stdio.h>

extern int expr(const char *str);
extern int expr_muldiv(const char *str);

int main()
{
	assert(expr("1") == 1);
	assert(expr("2") == 2);
	
	assert(expr("1+2") == 3);
	assert(expr("7-4") == 3);

	assert(expr("2+7-3") == 6);
	assert(expr("3+5-2+8-1") == 13);

//	assert(expr_muldiv("2*3*5/6") == 5);

	assert(expr("3+2*5") == 13);
	assert(expr("3*2-5") == 1);

	assert(expr("2*3*5/6") == 5);
	assert(expr("2*3+7/6") == 7);

	printf("OK!\n");
	return 0;
}
