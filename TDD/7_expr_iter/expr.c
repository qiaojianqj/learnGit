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

int mul_div(Context *pCtx);

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
		case '*':
			result = left * right;
			break;
		case '/':
			result = left / right;
			break;
		case '\0':
			result = left;
			break;
		default:
			break;
	}
	return result;
}

int add_sub(Context *pCtx)
{
	int result = mul_div(pCtx);
	while(isAddOrSub(pCtx))
	{
		char op = parseOp(pCtx);	
		int right = mul_div(pCtx);
		result = calc(result, op, right);
	}
	return result;
}

int expr(const char *str)
{
	Context ctx = {str, 0};
	return add_sub(&ctx);
}

bool isMulOrDiv(const Context *pCtx)
{
	return pCtx->str[pCtx->pos] == '*' || pCtx->str[pCtx->pos] == '/';
}

int mul_div(Context *pCtx)
{
	int result = parseNum(pCtx);
	while(isMulOrDiv(pCtx))
	{
		char op = parseOp(pCtx);	
		int right = parseNum(pCtx);
		result = calc(result, op, right);
	}
	return result;
}

