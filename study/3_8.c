#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    DIR *dp;
    struct dirent *dent;
    struct stat buf;
    int kind;

    if((dp = opendir(".")) == NULL) {
        perror("opendir");
        exit(1);
    }
    while(dent = readdir(dp)) {
        stat(dent->d_name, &buf);
        printf("Name : %s  ", dent->d_name);
        if((buf.st_mode & S_IFMT) == S_IFDIR)
            printf("Directory\n");
        else
            printf("File\n");
    }
    closedir(dp);
return 0;
}
