#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fork_1() {
  int childpid = fork();
  int i;

  printf("#  step1 before fork()!! \n");

  if (childpid == 0) {  // child process
    // The last element of char* const argv[] shall be NULL.
    char* execv_str[] = {"echo", "   executed by execv", NULL};
    if (execv("/bin/echo", execv_str) < 0) {
      perror("error on exec");
      exit(0);
    } 
    /* Child process was replaced by execv.
     * Following statements wil be skipped.
     */
    printf("## Child process finished");
  } else {  // parent process
    wait(&childpid);
    printf("## execv done \n");
  }

  printf("#  step2 after fork()!! \n");

  return 0;
}

int main(void) {
  fork_1();
  return 0;
}
