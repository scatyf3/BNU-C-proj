// 放弃维护屎山，打算从零开始迭代式开发，先编写一个能跑起来的版本

#include <stdio.h>
#include "stu_info.h"
#include <string.h>
#include <stdlib.h>
#include "debug.h"

#define BUFFERSIZE 100

#define ASK_FOR_INPUT()               \
    printf(">");                      \
    fgets(buffer, BUFFERSIZE, stdin); \
    strtok(buffer, "\r\n");

int main()
{
    int flag = 1;
    char buffer[BUFFERSIZE];

    int course_counter = 0;
    int stu_counter = 0;
    int state = 0;
    int loop_counter = 0;
    int cur_course_stu_counter = 1;

    int number_of_course = 0;
    int number_of_student = 0;

    while (flag != 0)
    {
        if (loop_counter == 0)
        {
            INIT()
            loop_counter++;
        }
        if (flag == 1)
        {
            printf("欢迎来到由BNU@scommune开发的学生信息管理系统，输入a/add进入数据输入模式，输入q/quit退出系统，输入c/cal进入成绩计算，输入s/search进入检索ᕙ(•̤᷆ ॒ ູ•̤᷇)ᕘ₊˚\n");
            ASK_FOR_INPUT()
            if (strcmp(buffer, "a") == 0 || strcmp(buffer, "add") == 0)
            {
                printf("进入编辑模式\n");
                flag = 2;
            }

            if (strcmp(buffer, "c") == 0 || strcmp(buffer, "cal") == 0)
            {
                printf("进入计算模式\n");
                flag = 4;
            }
            if (strcmp(buffer, "s") == 0 || strcmp(buffer, "search") == 0)
            {
                flag = 7;
            }
        }

        if (flag == 2)
        {
            printf("请输入你增加的课程名字，输入q/quit保存并退出\n");
            ASK_FOR_INPUT()
            int course_id = has_course_id(buffer);
            if (course_id == -1)
            {
                strcpy(course_name_table[course_counter], buffer);
                cur_course_number_of_stu[course_counter]=0;
                course_counter++;
                cur_course_stu_counter = 1;
                number_of_course++;
            }
            else
            {
                course_counter = course_id;
                cur_course_stu_counter = cur_course_number_of_stu[course_id];
            }

            flag = 3;
        }
        if (strcmp(buffer, "q") == 0 || strcmp(buffer, "quit") == 0)
        {
            printf("谢谢您的使用，信息已经被保存为CSV格式，再见 o(´^｀)o\n");
            FILE *fp = fopen("test_data/stu_total_score.csv", "w+");
            fprintf(fp, "ID,Name,score\n");
            for(int i=0;i<stu_counter;i++){
                fprintf(fp,"%d,%s,%lf\n",i,stu_name_table[i],cal_stu_average_score(i,course_score_table));
            }

            FILE *fp_course = fopen("test_data/course.csv", "w+");
            fprintf(fp_course, "ID,course_name,score\n");
            for(int i=0;i<course_counter;i++){
                fprintf(fp_course,"%d,%s,%lf\n",i,course_name_table[i],cal_course_average_score(i,course_score_table));
            }

            flag = 0;
            break;
        }
        if (flag == 3)
        {
            printf("正在输入%s课程成绩,输入f结束本课程成绩录入\n", course_name_table[course_counter]);
            printf("正在输入第%d个学生的姓名和课程成绩", cur_course_stu_counter);
            printf("请输入该名同学的姓名\n");
            printf(">");
            ASK_FOR_INPUT()
            int stu_id = has_stu_id(buffer);
            if (strcmp(buffer, "f") == 0 || strcmp(buffer, "finish") == 0)
            {
                flag = 1;
            }
            else
            {
                if (stu_id == -1)
                {
                    strcpy(stu_name_table[stu_counter], buffer);
                    stu_counter++;
                    number_of_student++;
                }
                cur_course_stu_counter++;
                cur_course_number_of_stu[course_counter - 1]++;
                // stu_counter在这里用作提醒不科学
                printf("正在输入当前课程第%d个学生的姓名和课程成绩", cur_course_stu_counter - 1);
                printf("请输入该名同学的分数\n");
                printf(">");
                ASK_FOR_INPUT()
                if (stu_id == -1)
                {
                    course_score_table[course_counter - 1][stu_counter - 1] = atof(buffer);
                }
                else
                {
                    course_score_table[course_counter-1][stu_id] = atof(buffer);
                }
                // printf("%lf",course_score_table[course_counter-1][stu_counter]);
                // debug_display_cur_counter(course_counter,stu_counter);
                //debug_show_course_score(course_counter-1,course_score_table);
            }

            // debug_show_course_score(course_counter,course_score_table);
        }
        if (flag == 4)
        {
            // 计算模式总界面
            printf("当前数据库中存有%d名学生成绩，%d个课程成绩\n", stu_counter, course_counter);
            printf("若想按照课程计算平均请输入：course\n");
            printf("若想按照课程计算平均请输入：student\n");
            ASK_FOR_INPUT()
            if (strcmp(buffer, "course") == 0)
            {
                flag = 5;
            }
            else if (strcmp(buffer, "student") == 0)
            {
                flag = 6;
            }
        }

        if (flag == 5)
        {
            // 按课程计算均分
            printf("请输入你想计算的课程名，输入back返回主界面\n");
            ASK_FOR_INPUT()
            if (strcmp(buffer, "back") == 0)
            {
                flag = 1;
            }
            else
            {
                int course_id = check_course_id(buffer);

                // printf("%d", course_id);
                //  debug_display_course_name_table(course_name_table);

                if (course_id == -1)
                {
                    printf("未找到您想查询的课程\n");
                }
                else
                {
                    // 数据保存无误，可能是courseid查询有问题
                    debug_show_course_score(course_id,course_score_table);
                    double ans = cal_course_average_score(course_id, course_score_table);
                    printf("您想查询的%s课程平均成绩为%lf", course_name_table[course_id], ans);
                }
            }
        }

        if (flag == 6)
        {
            // 按学生计算均分
            printf("请输入你想计算的学生姓名名，输入back返回主界面\n");
            ASK_FOR_INPUT()
            if (strcmp(buffer, "back") == 0)
            {
                flag = 1;
            }
            else
            {
                int stu_id = check_stu_id(buffer);
                if (stu_id == -1)
                {
                    printf("未找到您想查询的课程\n");
                }
                else
                {
                    // debug_show_course_score(0, course_score_table);
                    // debug_show_course_score(1, course_score_table);
                    double ans = cal_stu_average_score(stu_id, course_score_table);
                    printf("您想查询的%s学生平均成绩为%lf", stu_name_table[stu_id], ans);
                }
            }
        }
        if (flag == 7)
        {
            // 计算模式总界面
            printf("当前数据库中存有%d名学生成绩，%d个课程成绩\n", stu_counter, course_counter);
            printf("若想按照课程查找请输入：course\n");
            printf("若想按照学生查找请输入：student\n");
            ASK_FOR_INPUT()
            if (strcmp(buffer, "course") == 0)
            {
                flag = 8;
            }
            else if (strcmp(buffer, "student") == 0)
            {
                flag = 9;
            }
        }
        if (flag == 8)
        {
            // 按课程查找
            printf("请输入你想查找的课程\n");
            ASK_FOR_INPUT()
            int course_id = check_course_id(buffer);
            if (course_id == -1)
            {
                printf("未找到您想查询的课程\n");
            }
            else
            {
                printf("选了这门课程的同学有:");
                double sum = 0;
                double counter = 0;
                for (int i = 0; i < MAX_SIZE_OF_STU; i++)
                {
                    if (course_score_table[course_id][i] != -1)
                    {
                        printf("%s,", stu_name_table[i]);
                        sum += course_score_table[course_id][i];
                        counter++;
                    }
                }
                printf("这门课程的平均分为:%lf\n", sum / counter);
            }
        }

        if (flag == 9)
        {
            // 按学生查找
            printf("请输入你想查找的同学\n");
            ASK_FOR_INPUT()
            int stu_id = check_stu_id(buffer);
            if (stu_id == -1)
            {
                printf("未找到您想查询的学生\n");
            }
            else
            {
                printf("这名同学选择的课程有:");
                double sum = 0;
                double counter = 0;
                for (int i = 0; i < MAX_LENGTH; i++)
                {
                    if (course_score_table[i][stu_id] != -1)
                    {
                        printf("%s,", course_name_table[i]);
                        sum += course_score_table[i][stu_id]; // 输入多个课程，课程名显示有问题
                        counter++;
                    }
                }
                printf("这位同学的平均分为:%lf\n", sum / counter);
            }
        }

        loop_counter++;
    }

    // printf("done\n");

    // debug_show_course_score(0,course_score_table);
    return 0;
}
