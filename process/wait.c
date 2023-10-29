#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int rc;

  printf("hello world (pid: %d)\n", (int)getpid());
  rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed!\n");
    exit(1);
  } else if (rc == 0) {
    printf("hello I'm child (pid: %d)\n", (int)getpid());
  } else {
    // wait(int *status)
    // staus 주소는 종료상태를 저장하기 위한 용도 - 관심없으면 NULL
    int wc = wait(NULL);
    printf("hello I'm (pid: %d), parent of (pid: %d) (wc: %d)\n", (int)getpid(),
           rc, wc);
  }
  return (0);
}
