#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 10

int main (int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    printf("欢迎来到由BNU@scommune开发的学生信息管理系统， \n");
    while(fgets(buffer, BUFFERSIZE , stdin) != NULL)
    {
        printf("%s\n", buffer);
    }
    return 0;
}