#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void my_op(int);
main()
{
	sigset_t new_mask,old_mask,pending_mask;
	struct sigaction act;
	sigemptyset(&act.sa_mask);
	act.sa_flags=SA_SIGINFO;
	act.sa_sigaction=(void*)my_op;

	printf("the process pid is %d\n", getpid());

	if(sigaction(SIGRTMIN+10,&act,NULL))  // kill -SIGRTMIN+10 pid
		printf("install signal SIGRTMIN+10 error\n");

	sigemptyset(&new_mask);
	sigaddset(&new_mask,SIGRTMIN+10);

	if(sigprocmask(SIG_BLOCK, &new_mask,&old_mask))
		printf("block signal SIGRTMIN+10 error\n");

	sleep(20);	
	printf("now begin to get pending mask and unblock SIGRTMIN+10\n");

	if(sigpending(&pending_mask)<0)
		printf("get pending mask error\n");

	if(sigismember(&pending_mask,SIGRTMIN+10))
		printf("signal SIGRTMIN+10 is pending\n");

	if(sigprocmask(SIG_SETMASK,&old_mask,NULL)<0)
		printf("unblock signal error\n");

	printf("signal unblocked\n");
	sleep(3);
}

static void my_op(int signum)
{
	printf("receive signal %d \n",signum);
}
