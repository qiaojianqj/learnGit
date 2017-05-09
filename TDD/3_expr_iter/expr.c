/**
 *TDD开发三部军规
 *1. 先写测试用例，编译通过，执行测试用例不通过。
 *2. 快速实现代码，执行测试用例通过。
 *3. 重构优化，去除重复代码，抽象出领域规则。
 */
#include <stdbool.h>
typedef struct Context{
	char * str;
	int pos;
}Context;

int parseNum(Context *pCtx)
{
	return pCtx->str[pCtx->pos++] - '0';
}

char parseOp(Context *pCtx)
{
	return pCtx->str[pCtx->pos++];
}

bool isAddOrSub(const Context *pCtx)
{
	return pCtx->str[pCtx->pos] == '+' || pCtx->str[pCtx->pos] == '-';
}

int calc(int left, char op, int right)
{
	int result = 0;
	switch(op)
	{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '\0':
			result = left;
			break;
		default:
			break;
	}
	return result;
}

int expr(char *str)
{
	Context ctx = {str, 0};
	int result = parseNum(&ctx);
	while(isAddOrSub(&ctx))
	{
		char op = parseOp(&ctx);	
		int right = parseNum(&ctx);
		result = calc(result, op, right);
	}
	return result;
}

