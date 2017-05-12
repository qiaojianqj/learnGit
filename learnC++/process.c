#include <stdio.h>

int main()
{
	int child;
	char *args[] = {"/bin/echo", "Hello", "World", NULL};

	if(!(child = fork()))
	{
		/*child*/	
		printf("pid %d: %d is my father\n", getpid(), getppid());
		execve("/bin/echo", args, NULL);
		printf("pid %d: if get here, something is wrong\n", getpid());
	}
	else
	{
		/*father*/
		printf("pid %d: %d is my son\n", getpid(), child);
		wait(child, NULL, 0, NULL);
		printf("pid %d: done\n", getpid());
	}

	return 0;
}
