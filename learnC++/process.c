#include <stdio.h>
#include <wait.h>

int main()
{
	int child;
	int child_status;
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
		//wait(child, NULL, 0, NULL);
		wait (&child_status);
		if (WIFEXITED (child_status))
			printf ("the child proces exited normally, with exit code %d\n",WEXITSTATUS (child_status));
		else
			printf ("the child process exited abnormally\n");

		printf("pid %d: done\n", getpid());
	}

	return 0;
}
