#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

    struct stat st;
    stat("p1.c", &st);
    void* buf[100];
    int fd = open("p1.c", O_RDONLY);
    ssize_t n;
    ssize_t count = 0;
    while((n = read(fd, buf, 100)) > 0)
    {
        count += n;
    }
    printf("Read %ld bytes\n", count);
    close(fd);
    printf("File size: %ld\n", st.st_size);
    printf("File size: %ld\n", st.st_size);
    printf("Number of links: %lu\n", st.st_nlink);
    printf("File mode: %o\n", st.st_mode);
    printf("%d", O_RDWR);
    // and so on for the other members...
}