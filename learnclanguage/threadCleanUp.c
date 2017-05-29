#include <malloc.h>
#include <pthread.h>
/* 分配临时缓冲区。*/
void *allocate_buffer(size_t size) { return malloc(size); }
/* 释放临时缓冲区。*/
void deallocate_buffer(void *buffer) { free(buffer); }
void do_some_work() {
  /* 分配临时缓冲区。*/
  void *temp_buffer = allocate_buffer(1024);
  /* 为缓冲区注册清理句柄以确保当线程退出或被取消的时候自动释放。*/
  pthread_cleanup_push(deallocate_buffer, temp_buffer);
  /* 在这里完成一些任务,其中可能出现对 pthread_exit 的调用,
线程也可能在此期间被取消。*/
  int i;
  for (i = 0; i < 1024; ++i)
    ((char *)temp_buffer)[i] = i;
  printf("%d\n", ((char *)temp_buffer)[123]);
  printf("OK\n");
  pthread_exit(NULL);
  /* 取消对清理句柄的注册。因为我们传递了一个非零值作为参数, 清理句柄
   * deallocate_buffer 将被调用以释放缓存。*/
  pthread_cleanup_pop(1);
}

void *thread_function(void *para) {
  do_some_work();
  return NULL;
}

int main(int argc, char const *argv[]) {
  pthread_t thread_id;
  pthread_create(&thread_id, NULL, thread_function, NULL);
  pthread_join(thread_id, NULL);
  return 0;
}
