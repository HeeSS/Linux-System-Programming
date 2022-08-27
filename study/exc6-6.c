#include <sys/types.h>
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
            printf("Child Process : Begin\n");
            system("who");
            printf("Child Process : End\n");
            break; 
        default :   /* parent process */
            printf("Parent process : Begin\n");
            system("date");
            printf("Parent process : End\n");
            break; 
    }

    printf("End of ex6_5.c\n");
}
