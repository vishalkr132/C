#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{

    int file = open("text.txt" , O_WRONLY | O_CREAT , 0644);
    if(file < 0)
    {
        printf("failed to create file %d\n" , file);
    }

    char *buffer = "this is simple text";
    int bytes = write(file  , buffer , strlen(buffer));
    if(bytes < 0)
    {
        printf("failed to erite \n");
        close(file);
    }

    close(file);


    int fd = open("text.txt" , O_RDONLY);
    if(fd < 0)
    {
        printf("failed to open\n");
    }

    if(lseek(fd , 0 ,SEEK_SET) == -1)
    {
        printf("failed to set cur at beginnig\n");
    }
    char buf[50];
    int readBytes;
    while((readBytes = read(fd , buf , sizeof(buf) - 1 )) > 0)
    {
        buf[readBytes] = '\0';
        printf("%s" , buf);
    }

    return 0;
}

