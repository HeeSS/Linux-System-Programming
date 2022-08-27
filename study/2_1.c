#include <stdio.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int rfd, wfd, n, a, count;
    char buf[2], cbuf[4];
 
    if(argc != 2) {
        printf("error: argc != 2");
        exit(1);
    }
    rfd = open(argv[1], O_RDONLY);
    if(rfd == -1) {
        perror("open");
        exit(1);
    }
    count = 1; 
    sprintf(cbuf, "%d  ", count);
    if(write(1, cbuf, strlen(cbuf)) != strlen(cbuf)) 
		perror("write");
    while((n = read(rfd, buf, 1)) > 0) {
        if(write(1, buf, n) != n) 
			perror("write");
        if(buf[0] == '\n') {
            count++;
            sprintf(cbuf, "%d  ", count);
            if(write(1, cbuf, strlen(cbuf)) != strlen(cbuf)) 
				perror("write");
        }
    }
    if(n == -1) 
		perror("read");
    close(rfd);
    return 0;
}
