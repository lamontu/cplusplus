#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

void ChildProcess(const char* s1, const char* s2); // Child process prototype
void ParentProcess(void);  // Parent process prototype

int main(void) {
  pid_t pid1, pid2, pid;
  int status = 0;
  int i = 0;
  char buf[BUF_SIZE];

  printf("*** Parent is about to fork process 1. ***\n");
  if ((pid1 = fork()) < 0) {
    printf("Failed to fork process 1\n");
    exit(1);
  } else if (pid1 == 0) {
    ChildProcess("First", "  ");
  }

  printf("*** Parent is about to fork process 2. ***\n");
  if ((pid2 = fork()) < 0) {
    printf("Failed to fork process 2\n");
    exit(1);
  } else if (pid2 == 0) {
    ChildProcess("Second", "    ");
  }

  ParentProcess();

  // printf("*** Parent enters waiting status......\n", pid);
  // Equivalent to the next two statements 
  sprintf(buf, "*** Parent enters waiting status......\n");
  write(1, buf, strlen(buf));

  // pid = wait(NULL);  // Also OK
  pid = wait(&status);
  sprintf(buf, "*** Parent detects process %d was done. ***\n", pid);
  write(1, buf, strlen(buf));

  pid = wait(&status);
  sprintf(buf, "*** Parent detects process %d was done. ***\n", pid);
  write(1, buf, strlen(buf));

  printf("*** Parent exits. ***\n");
  exit(0);  
}

#define QUAD(x) (x*x*x*x)

void ParentProcess(void) {
  int a, b, c, d;
  int abcd, a4b4c4d4;
  int count = 0;
  char buf[BUF_SIZE];

  sprintf(buf, "Parent is about to compute the Armstrong number.\n");
  write(1, buf, strlen(buf));
  for (a = 0; a <= 9; ++a) {
    for (b = 0; b <= 9; ++b) {
      for (c = 0; c <= 9; ++c) {
        for (d = 0; d <= 9; ++d) {
          abcd = a*1000 + b*100 + c*10 + d;
          a4b4c4d4 = QUAD(a) + QUAD(b) + QUAD(c) + QUAD(d);
          if (abcd == a4b4c4d4) {
            sprintf(buf, "From parent: the %d Armstrong number is %d.\n",
                         ++count, abcd);
            write(1, buf, strlen(buf));
          }
        }
      }
    }
  }
  sprintf(buf, "From parent: there are %d Armstrong numbers.\n", count);
  write(1, buf, strlen(buf));
}

void ChildProcess(const char* number, const char* space) {
  pid_t pid;
  int i;
  char buf[BUF_SIZE];

  pid = getpid();
  sprintf(buf, "%s%s child process starts (pid = %d).\n", space, number, pid);
  write(1, buf, strlen(buf));

  for (i = 1; i <= MAX_COUNT; ++i) {
    sprintf(buf, "%s%s child's output, value = %d\n", space, number, i);
    write(1, buf, strlen(buf));
  }

  sprintf(buf, "%s%s child (pid = %d) is about to exit.\n", space, number, pid);
  write(1, buf, strlen(buf));

  exit(0);
}
