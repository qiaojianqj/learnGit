#include "semaphore.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h> // sleep
using namespace std;

int count = 0;            // 记录当前的读者数量
semaphore mutex("/", 1);  // 用于保护更新count变量时的互斥
semaphore rw("/home", 1); // 用于保证读者和写者的互斥

void *writer(void *arg) {
  rw.P(); // 互斥访问共享文件

  printf("  Writer %d start writing...\n", arg);
  sleep(1);
  printf("  Writer %d finish writing...\n", arg);

  rw.V(); // 释放共享文件
}

void *reader(void *arg) {
  mutex.P();      // 互斥访问count变量
  if (count == 0) // 当第一个读线程读文件时
    rw.P();       // 阻止写线程写
  ++count;        // 读者计数器加1
  mutex.V();      // 释放count变量

  printf("Reader %d start reading...\n", arg);
  sleep(1);
  printf("Reader %d finish reading...\n", arg);

  mutex.P();      // 互斥访问count变量
  --count;        // 读者计数器减1
  if (count == 0) // 当最后一个读线程读完文件
    rw.V();       // 允许写线程写
  mutex.V();      // 释放count变量
}

int main() {
  pthread_t id[8]; // 开6个读线程，2个写线程

  pthread_create(&id[0], NULL, reader, (void *)1);
  pthread_create(&id[1], NULL, reader, (void *)2);

  pthread_create(&id[2], NULL, writer, (void *)1);
  pthread_create(&id[3], NULL, writer, (void *)2);

  pthread_create(&id[4], NULL, reader, (void *)3);
  pthread_create(&id[5], NULL, reader, (void *)4);
  sleep(2);
  pthread_create(&id[6], NULL, reader, (void *)5);
  pthread_create(&id[7], NULL, reader, (void *)6);

  sleep(4);
  return 0;
}
