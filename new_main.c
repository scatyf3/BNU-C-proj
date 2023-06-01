//放弃维护屎山，打算从零开始迭代式开发，先编写一个能跑起来的版本

#include <stdio.h>
#include "new_stu_info.h"
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 100

#define ASK_FOR_INPUT() printf(">");\
            fgets(buffer, BUFFERSIZE, stdin);\
            strtok(buffer, "\r\n");

int main(){
    int flag = 1;
    char buffer[BUFFERSIZE];
    printf("欢迎来到由BNU@scommune开发的学生信息管理系统，输入a/add进入数据输入模式，输入q/quit退出系统\n");
    int course_counter = 0;
    int stu_counter = 0;
    int state = 0;
    int loop_counter = 0;
    int cur_course_stu_counter = 1;
    while(flag!=0){
        if(loop_counter==0){
            //初始化
            ASK_FOR_INPUT()
        }
        if(strcmp(buffer,"a")==0||strcmp(buffer,"add")==0){
            printf("进入编辑模式\n");
            flag=2;
        }
        if(flag==2){
            printf("请输入你增加的课程名字，输入q/quit保存并退出\n");
            ASK_FOR_INPUT()
            strcpy(course_name_table[course_counter],buffer);
            course_counter++;
            flag = 3;
            cur_course_stu_counter=1;
        }
        if(strcmp(buffer,"q")==0||strcmp(buffer,"quit")==0){
            printf("谢谢您的使用，信息已经被保存为CSV格式，再见");
            //TODO：记得增加CSV保存功能，或者删掉这段话
            flag=0;
            break;
        }
        if(flag == 3){
            printf("正在输入%s课程成绩\n",course_name_table[course_counter-1]); 
            if(state == 1){
                //stu_counter在这里用作提醒不科学
                printf("正在输入当前课程第%d个学生的姓名和课程成绩，输入f/finish两次结束",cur_course_stu_counter-1);
                printf("请输入该名同学的分数\n");
                printf(">");
                ASK_FOR_INPUT()
                course_score_table[stu_counter-1][course_counter-1]=atoi(buffer);
                state--;
            }
            else if(strcmp(buffer,"f")==0||strcmp(buffer,"finish")==0){
                flag = 2;
            }
            else if(state == 0){
                printf("正在输入第%d个学生的姓名和课程成绩，输入f/finish两次结束 ",cur_course_stu_counter);
                printf("请输入该名同学的姓名\n");
                printf(">");
                ASK_FOR_INPUT()
                strcpy(stu_name_table[stu_counter],buffer);
                state++;
                stu_counter++;
                cur_course_stu_counter++;
            }
        }
        //printf("done\n");
        loop_counter++;
    }

    return 0;
}