#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// 到时候用makefile改写一下

#define MAX_SIZE 1000

int main()
{
    int type;
    printf("请输入数据输入模式:1-学生CSV,2-课程CSV,3-学生成绩命令行输入,4-课程成绩命令行输入\n");
    scanf("%d", &type);
    char row[100];
    char *token;
    struct student s[MAX_SIZE];
    struct course c[MAX_SIZE];

    int size_of_stu = 0;
    int counter = 0;

    FILE *stu_fp = fopen("test_data/student.csv", "r");
    FILE *cour_fp = fopen("test_data/course.csv", "r");

    int flag = 1;
    int i=0;
    
    switch (type)
    {
    case 1:
        // 以学生模式读取CSV文件
        // 可以用来测试的路径: test_data/course.csv , test_data/student.csv

        if (stu_fp == NULL)
        {
            fprintf(stderr, "fopen() failed.\n");
            exit(EXIT_FAILURE);
        }

        while (fgets(row, 100, stu_fp) != NULL)
        {
            printf("Row: %s", row);
            token = strtok(row, ",");
            struct student tmp;
            int i = 0;
            while (token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, ","); // 该函数返回类型是char *
                if (i == 0)
                {
                    tmp.ID = atoi(token);
                }
                if (i == 1)
                {
                    tmp.s_name = token;
                }
                if (i == 2)
                {
                    tmp.total_score = atof(token);
                }
                i++;
            }
            s[counter] = tmp;
            counter++;
        }
        size_of_stu = counter;
        fclose(stu_fp);
        break;

    case 2:
        // 以课程模式读取CSV文件,似乎未完成
        // 可以用来测试的路径: test_data/course.csv , test_data/student.csv

        if (cour_fp == NULL)
        {
            fprintf(stderr, "fopen() failed.\n");
            exit(EXIT_FAILURE);
        }
        while (fgets(row, 100, cour_fp) != NULL)
        {
            printf("Row: %s", row);
            token = strtok(row, ",");
            struct student tmp;
            int i = 0;
            while (token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, ",");
                if (i == 0)
                {
                    tmp.ID = atoi(token);
                }
                if (i == 1)
                {
                    tmp.s_name = token;
                }
                if (i == 2)
                {
                    tmp.total_score = atof(token);
                }
                i++;
            }
            s[counter] = tmp;
            counter++;
        }
        size_of_stu = counter;
        fclose(cour_fp);
        break;
    
    case 3:
        //手动输入学生信息
        printf("请依次输入学生学号，姓名，随后顺序输入课程名和该生在本课程的成绩");
        printf("输入q退出");
        struct student tmp;
        while(flag!=0){
            scnaf("%d\n",tmp.ID);
            printf("done");
            scanf("%d\n",tmp.s_name);
            printf("done");
            scanf("%d\n",tmp.c_list[i]->c_name);
            printf("done");
            scanf("%d\n",tmp.c_list[i]->c_score);
            printf("done");


            
            

        }

        break;
    


    default:
        break;
    }
    return 0;
}
