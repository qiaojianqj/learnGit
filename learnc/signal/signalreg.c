#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void new_op(int,siginfo_t*,void*);

int main(int argc,char**argv)
{
	struct sigaction act;
	int sig;
	pid_t pid;		
	
	printf("usage: argv[0]:progname, argv[1]: signum\n");
	pid=getpid();
	printf("the process pid is %d\n", getpid());

	sig=atoi(argv[1]);	
	sigemptyset(&act.sa_mask);
	act.sa_sigaction=new_op;
	act.sa_flags=SA_SIGINFO;
	if(sigaction(sig,&act,NULL)<0)
	{
		printf("install sigal error\n");
	}

	while(1)
	{
		sleep(5);
		printf("wait for the signal\n");
	}
}

void new_op(int signum,siginfo_t *info,void *myact)
{
	printf("the int value is %d \n",info->si_int);
}
