#include "semaphore.h"

semaphore::semaphore(const char *path, int value) {
  key_t key;
  /*获取key值*/
  if ((key = ftok(path, 'z')) < 0) {
    perror("ftok error");
    exit(1);
  }

  /*创建信号量集，其中只有一个信号量*/
  if ((sem_id = semget(key, 1, IPC_CREAT | 0666)) == -1) {
    perror("semget error");
    exit(1);
  }

  init_sem(value);
}

semaphore::~semaphore() {
  union semunion tmp;
  if (semctl(sem_id, 0, IPC_RMID, tmp) == -1) {
    perror("Delete Semaphore Error");
    exit(1);
  }
}

void semaphore::P() {
  struct sembuf sbuf;
  sbuf.sem_num = 0; /*序号*/
  sbuf.sem_op = -1; /*P操作*/
  sbuf.sem_flg = SEM_UNDO;

  if (semop(sem_id, &sbuf, 1) == -1) {
    perror("P operation Error");
  }
}

void semaphore::V() {
  struct sembuf sbuf;
  sbuf.sem_num = 0; /*序号*/
  sbuf.sem_op = 1;  /*V操作*/
  sbuf.sem_flg = SEM_UNDO;

  if (semop(sem_id, &sbuf, 1) == -1) {
    perror("V operation Error");
  }
}

// 初始化信号量
int semaphore::init_sem(int value) {
  union semunion tmp;
  tmp.val = value;
  if (semctl(sem_id, 0, SETVAL, tmp) == -1) {
    perror("Init Semaphore Error");
    return -1;
  }
  return 0;
}
