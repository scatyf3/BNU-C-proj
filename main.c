#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
//到时候用makefile改写一下

#define MAX_SIZE 1000

int main(){
    int type;
    printf("请输入数据输入模式:1-学生CSV,2-课程CSV,3-学生成绩命令行输入,4-课程成绩命令行输入\n");
    scanf("%d",&type);
    switch (type)
    {
    char file_path[100];
    gets(file_path);
    //可以用来测试的路径: test_data/course.csv , test_data/student.csv
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen() failed.\n");
        exit(EXIT_FAILURE);
    }
    char row[100];
    char *token;
    struct student s[MAX_SIZE];
    struct course c[MAX_SIZE];

    int size_of_stu=0;
    int counter = 0;
    case 1:
    //以课程模式读取CSV文件
    
    while (fgets(row, 100, fp) != NULL) {
        printf("Row: %s", row);
        token = strtok(row, ","); 
        struct student tmp;
        int i=0;
        while (token!= NULL) {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
            if(i==0){
                tmp.ID=token-'0';
            }
            if(i==1){
                tmp.s_name=token;
            }
            if(i==2){
                tmp.total_score=atof(token);
            }
        }
        s[counter]=tmp;
        counter++;
    }
    size_of_stu=counter;
    fclose(fp);
        break;
    case 2:
    //以学生模式读取CSV文件
    while (fgets(row, 100, fp) != NULL) {
        printf("Row: %s", row);
        token = strtok(row, ","); 
        struct student tmp;
        int i=0;
        while (token!= NULL) {
            printf("Token: %s\n", token);
            token = strtok(NULL, ",");
            if(i==0){
                tmp.ID=token-'0';
            }
            if(i==1){
                tmp.s_name=token;
            }
            if(i==2){
                tmp.total_score=atof(token);
            }
        }
        s[counter]=tmp;
        counter++;
    }
    size_of_stu=counter;
    fclose(fp);
    break;
    default:
        break;
    }
    return 0;
}
