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
    printf("hello I'm (pid: %d), parent of (pid: %d) \n", (int)getpid(), rc);
  }
  return (0);
}
