
#include <stdio.h>

int main()
{
	int a = 8, b = 5;
//	printf("sub: %0x\n", sub)
	printf("a - b = %d\n", sub(a, b));
//	printf("add: %0x\n", add)
	printf("a + b = %d\n", add(a, b));
	return 0;
}


/*
#include <stdio.h>
#include <dlfcn.h>

int main()
{
	void* handle = dlopen ("libcalc.so", RTLD_LAZY);
	int (*test)(int , int) = dlsym (handle, "add");
	int result = (*test)(8, 5);
	printf("a + b = %d\n", result);

	test = dlsym(handle, "sub");
	result = (*test)(8, 5);
	printf("a - b = %d\n", result);

	dlclose (handle);
	return 0;
}
*/
