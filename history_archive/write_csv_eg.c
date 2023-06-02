// 2-1.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("tmp.csv", "w+");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "ID,Name,Points\n");
    fprintf(fp, "1,qwe,1.1\n");

    int id = 2;
    char *name = "asd";
    float point = 2.2;
    fprintf(fp, "%d,%s,%f\n", id, name, point);

    // special symbols
    fprintf(fp, "3,\"z,xc\",3.3\n");
    fprintf(fp, "4,\"qw\nas\",4.4\n");
    fprintf(fp, "5,\"\"aszx\"\",5.5\n");

    fclose(fp);
    return 0;
}