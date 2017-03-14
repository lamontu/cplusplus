#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fork_1() {
  int childpid = fork();
  int i;

  printf("#  step1 before fork()!! \n");

  if (childpid == 0) {  // child process
    if (execl("/bin/echo", "echo", "executed by execl", NULL) < 0) {
      perror("error on exec");
      exit(0);
    } 
    /* Child process was replaced by execv.
     * Following statements wil be skipped.
     */
    printf("## Child process finished");
  } else {  // parent process
    wait(&childpid);
    printf("## execl done \n");
  }

  printf("#  step2 after fork()!! \n");

  return 0;
}

int main(void) {
  fork_1();
  return 0;
}
