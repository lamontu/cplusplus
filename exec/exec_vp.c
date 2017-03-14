#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fork_1() {
  int childpid = fork();
  int i;

  printf("#  step1 before fork()!! \n");

  if (childpid == 0) {  // child process
    char* execvp_str[] = {"bash", "-c", 
                          "echo executed by execvp > ./abc.txt", NULL};
    if (execvp("bash", execvp_str) < 0) {
      perror("error on exec");
      exit(0);
    } 
    /* Child process was replaced by execv.
     * Following statements wil be skipped.
     */
    printf("## Child process finished");
  } else {  // parent process
    wait(&childpid);
    printf("## execvp done \n");
  }

  printf("#  step2 after fork()!! \n");

  return 0;
}

int main(void) {
  fork_1();
  return 0;
}
