#include <pthread.h>
#include <stdio.h>

/* print_function 的参数 */
struct char_print_parms {
  /* 用于输出的字符 */
  char character;
  /* 输出的次数 */
  int count;
};

/* 按照 PARAMETERS 提供的数据,输出一定数量的字符到 stderr。
PARAMETERS 是一个指向 struct char_print_parms 的指针 */
void *char_print(void *parameters) {
  /* 将参数指针转换为正确的类型 */
  struct char_print_parms *p = (struct char_print_parms *)parameters;
  int i;
  for (i = 0; i < p->count; ++i)
    fputc(p->character, stderr);
  fputc('\n', stderr);
  return NULL;
}

int main() {
  pthread_t thread1_id;
  pthread_t thread2_id;
  struct char_print_parms thread1_args;
  struct char_print_parms thread2_args;
  /* 创建一个输出 300 个 x 的线程 */
  thread1_args.character = 'x';
  thread1_args.count = 300;
  pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

  /* 创建一个输出 200 个 o 的线程 */
  thread2_args.character = 'o';
  thread2_args.count = 200;
  pthread_create(&thread2_id, NULL, &char_print, &thread2_args);

  /* 确保第一个线程结束 */
  pthread_join(thread1_id, NULL);
  /* 确保第二个线程结束 */
  pthread_join(thread2_id, NULL);

  /* 现在我们可以安全地返回 */
  printf("thread1: %d and thread2: %d finished!\n", thread1_id, thread2_id);
  return 0;
}
