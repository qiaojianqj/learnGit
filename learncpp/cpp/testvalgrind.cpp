#include <iostream>

int main()
{
	char *pMych = new char[100];
	pMych[10] = 'a';
	delete [] pMych;
	return 0;
}
