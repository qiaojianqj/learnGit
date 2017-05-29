#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

main(int argc,char**argv)
{
	pid_t pid;
	int signum;
	union sigval mysigval;

	printf("usage: argv[0]:progname, argv[1]: signum, argv[2]: pid\n");
	signum=atoi(argv[1]);
	pid=(pid_t)atoi(argv[2]);
	mysigval.sival_int=8;//不代表具体含义，只用于说明问题
	if(sigqueue(pid,signum,mysigval)==-1)
		printf("send error\n");
	sleep(2);
}
