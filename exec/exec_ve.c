#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int fork_1() {
  int childpid = fork();
  int i;

  printf("#  step1 before fork()!! \n");

  if (childpid == 0) {  // child process
    // The last element of char* const argv[] shall be NULL.
    char* execve_str[] = {"env", NULL};
    // The last element of char* const envp[] shall be NULL.
    char* env[] = {"PATH=/tmp", "USER=lei", "STATUS=testing", NULL}; 
    if (execve("/usr/bin/env", execve_str, env) < 0) {
      perror("error on exec");
      exit(0);
    } 
    /* Child process was replaced by execv.
     * Following statements wil be skipped.
     */
    printf("## Child process finished");
  } else {  // parent process
    wait(&childpid);
    printf("## execve done \n");
  }

  printf("#  step2 after fork()!! \n");

  return 0;
}

int main(void) {
  fork_1();
  return 0;
}
