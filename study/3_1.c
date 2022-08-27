#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    struct stat buf;
    int kind;
    char mode[10] = "---------";

    if(argc != 2) {
        printf("error: argc != 2");
        exit(1);
    }
    stat(argv[1], &buf);
    printf("���ϸ� : %s\n", argv[1]);
    printf("inode��ȣ : %u\n", buf.st_ino);
    kind = buf.st_mode & S_IFMT;
    switch(kind) {
        case S_IFIFO:
            printf("������ ���� : FIFO\n");
            break; 
        case S_IFDIR:
            printf("������ ���� : ���丮\n");
            break; 
        case S_IFREG:
            printf("������ ���� : �Ϲ� ����\n");
            break; 
    }
    if((buf.st_mode & S_IRUSR) != 0) mode[0] = 'r';
    if((buf.st_mode & S_IWUSR) != 0) mode[1] = 'w';
    if((buf.st_mode & S_IXUSR) != 0) mode[2] = 'x';
    if((buf.st_mode & S_IRGRP) != 0) mode[3] = 'r';
    if((buf.st_mode & S_IWGRP) != 0) mode[4] = 'w';
    if((buf.st_mode & S_IXGRP) != 0) mode[5] = 'x';
    if((buf.st_mode & S_IROTH) != 0) mode[6] = 'r';
    if((buf.st_mode & S_IWOTH) != 0) mode[7] = 'w';
    if((buf.st_mode & S_IXOTH) != 0) mode[8] = 'x';
    printf("���� ���� : %s\n", mode);
    printf("UID : %d\n", buf.st_uid);
    printf("���� ���� �ð� : %s\n", ctime(&buf.st_mtim.tv_sec));
    return 0;
}
