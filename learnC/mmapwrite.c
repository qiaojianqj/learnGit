#include <stdlib.h>
#include <errno.h>
       #include <stdio.h>
       #include <fcntl.h>
       #include <sys/mman.h>
       #include <sys/stat.h>
       #include <time.h>
       #include <unistd.h>
       #define FILE_LENGTH 4096*4
/* 在从 low 到 high 的范围中返回一个平均分布的随机数 */
       int random_range (unsigned const low, unsigned const high)
       {
        unsigned const range = high - low + 1;
return low + (int) (((double) range) * rand() / (RAND_MAX + 1.0)); }
       int main (int argc, char* const argv[])
       {
       int fd;
        void* file_memory;
/* 为随机数发生器提供种子 */ srand (time (NULL));
/* 准备一个文件使之长度足以容纳一个无符号整数 */
fd = open ("tmpfile", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
if (fd < 0)
{
	printf("open file failed\n");
	exit(1);
}
        lseek (fd, FILE_LENGTH+1, SEEK_SET);
        write (fd, "", 1);
        lseek (fd, 0, SEEK_SET);
/* 创建映射内存 */
file_memory = mmap (0, FILE_LENGTH, PROT_WRITE, MAP_SHARED, fd, 0);
if(file_memory == MAP_FAILED)
{
	fprintf(stderr, "mmap failed: %s\n", strerror(errno));
	exit(1);
}
close (fd);
/* 将一个随机整数写入映射的内存区域 */
sprintf((char*) file_memory, "%d\n", random_range (-100, 100));
/* 释放内存块(不是必需,因为程序即将退出而映射内存将被自动释放) */ munmap (file_memory, FILE_LENGTH);
return 0; }
