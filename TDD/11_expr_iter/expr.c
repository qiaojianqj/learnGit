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

typedef int (*HIGH_OPER)(Context *pCtx);
typedef bool (*IS_LOW_OP)(const Context *pCtx);

int parseNum(Context *pCtx)
{
	return pCtx->str[pCtx->pos++] - '0';
}

char parseOp(Context *pCtx)
{
	return pCtx->str[pCtx->pos++];
}

void parseLeftBracket(Context *pCtx)
{
	if(pCtx->str[pCtx->pos] == '(')
	{
		pCtx->pos++;
	}
}

void parseRightBracket(Context *pCtx)
{
	if(pCtx->str[pCtx->pos] == ')')
	{
		pCtx->pos++;
	}
}

bool isAddOrSub(const Context *pCtx)
{
	return pCtx->str[pCtx->pos] == '+' || pCtx->str[pCtx->pos] == '-';
}

bool isMulOrDiv(const Context *pCtx)
{
	return pCtx->str[pCtx->pos] == '*' || pCtx->str[pCtx->pos] == '/';
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

int oper(Context *pCtx, HIGH_OPER pHighOper, IS_LOW_OP pIsLowOp)
{
	int result = pHighOper(pCtx);
	while(pIsLowOp(pCtx))
	{
		char op = parseOp(pCtx);
		int right = pHighOper(pCtx);
		result = calc(result, op, right);
	}
	return result;
}

int mul_div(Context *pCtx)
{
	return oper(pCtx, parseNum, isMulOrDiv);
}

int add_sub(Context *pCtx)
{
	return oper(pCtx, mul_div, isAddOrSub);
}

int expr(const char *str)
{
	Context ctx = {str, 0};
	return add_sub(&ctx);
}

int parseBracketNum(Context *pCtx)
{
	int result = 0;
	parseLeftBracket(pCtx);
	result = add_sub(pCtx);
	parseRightBracket(pCtx);
	return result;
}

int expr_bracket(const char *str)
{
	Context ctx = {str, 0};
	int result = 0;
	result = parseBracketNum(&ctx);
	while(isAddOrSub(&ctx))
	{
		char op = parseOp(&ctx);
		int right = parseBracketNum(&ctx);
		result = calc(result, op, right);
	}
	return result;
}

