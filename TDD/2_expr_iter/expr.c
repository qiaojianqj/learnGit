/**
 *TDD开发三部军规
 *1. 先写测试用例，编译通过，执行测试用例不通过。
 *2. 快速实现代码，执行测试用例通过。
 *3. 重构优化，去除重复代码，抽象出领域规则。
 */

int expr(const char *str)
{
	int left = *str++ - '0';
	char op = *str++;
	int right = *str - '0'; 
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
		default:
			break;
	}
	return result;
}

