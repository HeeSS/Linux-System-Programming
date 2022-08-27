#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

main() {
    int status;
    pid_t pid;

    switch(pid = fork()) {
        case -1 :  /* fork failed */
            perror("fork");
            exit(1);
            break;
        case 0 :   /* child process */
            sleep(1);
            printf("--> Child Process\n");
            if(execl("/usr/bin/who", "who", (char *)NULL) == -1){
                perror("execl");
                exit(1);
            }
            exit(0);
            break;
        default :   /* parent process */
            printf("--> Parent process - My PID:%d\n", getpid());
            printf("Parent still wait...\n"); 
            while(waitpid(pid, &status, WNOHANG) == 0);
            printf("Child Exit Status : %d\n", status>>8);
            break; 
    }
}
