#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fork_1() {
  int childpid = fork();
  int i;

  printf("#  step1 before fork()!! \n");

  if (childpid == 0) {  // child process
    for (i = 1; i <= 8; ++i) {
      printf("   This is child process. \n");
    }
    printf("## Child process finished! \n"); 

    // exit the child process in if statement.
    exit(0);  
  } else {  // parent process
    // block the parent process until one of its child process exits
    wait(&childpid);
    for (i = 1; i <= 8; ++i) {
      printf("   This is parent process. \n");
    }
    printf("## Parent process finished! \n");
  }

  printf("#  step2 after fork()!! \n");

  return 0;
}

int main(void) {
  fork_1();
  return 0;
}
