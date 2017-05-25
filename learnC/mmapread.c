#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILE_LENGTH 4096*4 

int main (int argc, char* const argv[])
{
	int fd;
    void* file_memory;
    int integer;
/* 打开文件 */
	fd = open ("/tmp/tmpfile", O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		printf("open file failed\n");
		exit(1);
	}
/* 创建映射内存 */
	file_memory = mmap (0, FILE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED/*MAP_PRIVATE*/, fd, 0);
	if(file_memory == MAP_FAILED)
	{
		fprintf(stderr, "mmap failed: %s\n", strerror(errno));
		exit(1);
	}
	close (fd);
/* 读取整数,输出,然后将其倍增 */
	sscanf ((const char *)file_memory, "%d", &integer);
	printf ("value: %d\n", integer);
	sprintf ((char*) file_memory, "%d\n", 2 * integer); /* 释放内存(非必须,因为程序就此结束)*/
	munmap (file_memory, FILE_LENGTH);
	return 0; 
}
