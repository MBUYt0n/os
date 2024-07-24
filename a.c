#include <stdio.h>
#include <stdlib.h> 

int main()
{
    FILE *fp = fopen("/home/shusrith/Pictures/412679-Linux-gradient-Unix-Arch-Linux-technology-operating.png", "rb");
    while(1)
    {
        char c = fgetc(fp);
        if(feof(fp))
        {
            break;
        }
        printf("%c", c);
    }
}