#include <pthread.h>
#include <stdio.h>

#define MAX 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER;  //是否队满
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER; //是否队空

int top = 0;
int bottom = 0;

void *produce(void *arg) {
  int i;
  for (i = 0; i < MAX * 2; i++) {
    pthread_mutex_lock(&mutex);
    while ((top + 1) % MAX == bottom) {
      printf("full! producer is waiting\n");
      pthread_cond_wait(&notfull, &mutex); //等待队不满
    }

    top = (top + 1) % MAX;
    printf("now top is %d\n", top);
    pthread_cond_signal(&notempty); //发出队非空的消息

    pthread_mutex_unlock(&mutex);
  }
  return (void *)1;
}

void *consume(void *arg) {
  int i;
  for (i = 0; i < MAX * 2; i++) {
    pthread_mutex_lock(&mutex);
    while (top % MAX == bottom) {
      printf("empty! consumer is waiting\n");
      pthread_cond_wait(&notempty, &mutex); //等待队不空
    }
    bottom = (bottom + 1) % MAX;
    printf("now bottom is %d\n", bottom);
    pthread_cond_signal(&notfull); //发出队不满的消息

    pthread_mutex_unlock(&mutex);
  }

  return (void *)2;
}

int main(int argc, char *argv[]) {
  pthread_t thid1;
  pthread_t thid2;
  pthread_t thid3;
  pthread_t thid4;

  int ret1;
  int ret2;
  int ret3;
  int ret4;

  pthread_create(&thid1, NULL, produce, NULL);
  pthread_create(&thid2, NULL, consume, NULL);
  pthread_create(&thid3, NULL, produce, NULL);
  pthread_create(&thid4, NULL, consume, NULL);

  pthread_join(thid1, (void **)&ret1);
  pthread_join(thid2, (void **)&ret2);
  pthread_join(thid3, (void **)&ret3);
  pthread_join(thid4, (void **)&ret4);

  return 0;
}
