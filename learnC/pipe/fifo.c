/*
 *fifo打开规则：
 *如果当前打开操作是为读而打开FIFO时，若已经有相应进程为写而打开该FIFO，则当前打开操作将成功返回；否则，可能阻塞直到有相应进程为写而打开该FIFO（当前打开操作设置了阻塞标志）；或者，成功返回（当前打开操作没有设置阻塞标志）。

 *如果当前打开操作是为写而打开FIFO时，如果已经有相应进程为读而打开该FIFO，则当前打开操作将成功返回；否则，可能阻塞直到有相应进程为读而打开该FIFO（当前打开操作设置了阻塞标志）；或者，返回ENXIO错误（当前打开操作没有设置阻塞标志）。
 *
 *fifo读写规则：
 *从FIFO中读取数据：
 约定：如果一个进程为了从FIFO中读取数据而阻塞打开FIFO，那么称该进程内的读操作为设置了阻塞标志的读操作。

 *如果有进程写打开FIFO，且当前FIFO内没有数据，则对于设置了阻塞标志的读操作来说，将一直阻塞。对于没有设置阻塞标志读操作来说则返回-1，当前errno值为EAGAIN，提醒以后再试。
 
 *对于设置了阻塞标志的读操作说，造成阻塞的原因有两种：当前FIFO内有数据，但有其它进程在读这些数据；另外就是FIFO内没有数据。解阻塞的原因则是FIFO中有新的数据写入，不论信写入数据量的大小，也不论读操作请求多少数据量。

 *读打开的阻塞标志只对本进程第一个读操作施加作用，如果本进程内有多个读操作序列，则在第一个读操作被唤醒并完成读操作后，其它将要执行的读操作将不再阻塞，即使在执行读操作时，FIFO中没有数据也一样（此时，读操作返回0）。
 如果没有进程写打开FIFO，则设置了阻塞标志的读操作会阻塞。
 注：如果FIFO中有数据，则设置了阻塞标志的读操作不会因为FIFO中的字节数小于请求读的字节数而阻塞，此时，读操作会返回FIFO中现有的数据量。

 *向FIFO中写入数据：
 约定：如果一个进程为了向FIFO中写入数据而阻塞打开FIFO，那么称该进程内的写操作为设置了阻塞标志的写操作。

 *对于设置了阻塞标志的写操作：
 当要写入的数据量不大于PIPE_BUF时，linux将保证写入的原子性。如果此时管道空闲缓冲区不足以容纳要写入的字节数，则进入睡眠，直到当缓冲区中能够容纳要写入的字节数时，才开始进行一次性写操作。
 当要写入的数据量大于PIPE_BUF时，linux将不再保证写入的原子性。FIFO缓冲区一有空闲区域，写进程就会试图向管道写入数据，写操作在写完所有请求写的数据后返回。

 *对于没有设置阻塞标志的写操作：
 当要写入的数据量大于PIPE_BUF时，linux将不再保证写入的原子性。在写满所有FIFO空闲缓冲区后，写操作返回。
 当要写入的数据量不大于PIPE_BUF时，linux将保证写入的原子性。如果当前FIFO空闲缓冲区能够容纳请求写入的字节数，写完后成功返回；如果当前FIFO空闲缓冲区不能够容纳请求写入的字节数，则返回EAGAIN错误，提醒以后再写；
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

#define FIFO_SERVER "/tmp/fifoserver"
int handle_client(char*);

main(int argc,char** argv)
{
	int r_rd;
	int w_fd;
	pid_t pid;
	if((mkfifo(FIFO_SERVER,O_CREAT|O_EXCL)<0)&&(errno!=EEXIST))
		printf("cannot create fifoserver\n");
	handle_client(FIFO_SERVER);
}

int handle_client(char* arg)
{
  int ret;

  ret=w_open(arg);
  switch(ret)
  {
  	case 0:
  	{	
	  	printf("open %s error\n",arg);
	  	printf("no process has the fifo open for reading\n");
		break;
  	}
  	case 1:
  	{
  		printf("something wrong with open the fifo except for ENXIO");
		break;
  	}
  	case 2:
  	{
  		printf("open server for noblock writing ok\n");
		break;
  	}
  	default:
  	{
  		printf("w_no_r return ----\n");
		break;
  	}
  }		

  unlink(FIFO_SERVER);
  return -1;
}

//0  open error for no reading
//1 open error for other reasons
//2  open ok
int w_open(char*arg)
{
	open(arg,O_RDONLY|O_NONBLOCK,0);
	if(open(arg,O_WRONLY|O_NONBLOCK,0)==-1)
	{	if(errno==ENXIO)
		{
			return 0;
		}
		else
		return 1;
	}
	return 2;
	
}

