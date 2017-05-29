/*
 *管道的主要局限性正体现在它的特点上：
 *只支持单向数据流；
 *只能用于具有亲缘关系的进程之间；
 *没有名字；
 *管道的缓冲区是有限的（管道制存在于内存中，在管道创建时，为缓冲区分配一个页面大小）；
 *管道所传送的是无格式字节流，这就要求管道的读出方和写入方必须事先约定好数据的格式，比如多少字节算作一个消息（或命令、或记录）等等；
 *
 *验证管道写端对读端存在的依赖性
 *只有在管道的读端存在时，向管道中写入数据才有意义。否则，向管道中写入数据的进程将收到内核传来的SIFPIPE信号，应用程序可以处理该信号，也可以忽略（默认动作则是应用程序终止
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
main()
{
	int pipe_fd[2];
	pid_t pid;
	char r_buf[4];
	char* w_buf;
	int writenum;
	int r_num;
	int cmd;
	
	memset(r_buf,0,sizeof(r_buf));
	if(pipe(pipe_fd)<0)
	{
		printf("pipe create error\n");
		return -1;
	}
	
	if((pid=fork())==0)
	{
		//close(pipe_fd[0]);
		close(pipe_fd[1]);
		sleep(5);	
		r_num=read(pipe_fd[0],r_buf,4);
		printf(	"read num is %d   the data read from the pipe is %d\n",r_num,atoi(r_buf));
		close(pipe_fd[0]);
		exit(0);
	}
	else if(pid>0)
	{
	sleep(1);  //等待子进程完成关闭读端的操作
	close(pipe_fd[0]);//write
	w_buf="111";
	printf("ready to write\n");
	if((writenum=write(pipe_fd[1],w_buf,4))==-1)
		printf("write to pipe error\n");
	else	
		printf("the bytes write to pipe is %d \n", writenum);
	
	close(pipe_fd[1]);
	}	
}
