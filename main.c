//放弃维护屎山，打算从零开始迭代式开发，先编写一个能跑起来的版本

#include <stdio.h>
#include "stu_info.h"
#include <string.h>
#include <stdlib.h>
#include "debug.h"

#define BUFFERSIZE 100

#define ASK_FOR_INPUT() printf(">");\
            fgets(buffer, BUFFERSIZE, stdin);\
            strtok(buffer, "\r\n");

int main(){
    int flag = 1;
    char buffer[BUFFERSIZE];
    
    int course_counter = 0;
    int stu_counter = 0;
    int state = 0;
    int loop_counter = 0;
    int cur_course_stu_counter = 1;

    INIT()

    while(flag!=0){
        if(loop_counter==0){
            //初始化?
            
            loop_counter++;
        }
        if(flag==1){
            printf("欢迎来到由BNU@scommune开发的学生信息管理系统，输入a/add进入数据输入模式，输入q/quit退出系统，输入c/cal进入成绩计算\n");
            ASK_FOR_INPUT()
        }
        if(strcmp(buffer,"a")==0||strcmp(buffer,"add")==0){
            printf("进入编辑模式\n");
            flag=2;
        }

        if(strcmp(buffer,"c")==0||strcmp(buffer,"cal")==0){
            printf("进入计算模式\n");
            flag=4;
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
            printf("正在输入%s课程成绩,输入f结束本课程成绩录入\n",course_name_table[course_counter]); 
            if(state == 0){
                printf("正在输入第%d个学生的姓名和课程成绩",cur_course_stu_counter);
                printf("请输入该名同学的姓名\n");
                printf(">");
                ASK_FOR_INPUT()
                if(strcmp(buffer,"f")==0||strcmp(buffer,"finish")==0){
                    flag = 1;
                }
                else{
                    strcpy(stu_name_table[stu_counter],buffer);
                cur_course_number_of_stu[course_counter-1]++;
                state++;
                stu_counter++;
                cur_course_stu_counter++;
                }
                
            }
            if(state == 1){
                //stu_counter在这里用作提醒不科学
                printf("正在输入当前课程第%d个学生的姓名和课程成绩",cur_course_stu_counter-1);
                printf("请输入该名同学的分数\n");
                printf(">");
                ASK_FOR_INPUT()
                course_score_table[course_counter-1][stu_counter-1]=atof(buffer);
                //printf("%lf",course_score_table[course_counter-1][stu_counter]);
                state--;
                //debug_display_cur_counter(course_counter,stu_counter);
            }
            
            //debug_show_course_score(course_counter,course_score_table);
        }


        if(flag==4){
            //计算模式总界面
            printf("当前数据库中存有%d名学生成绩，%d个课程成绩\n",stu_counter,course_counter);
            printf("若想按照课程计算平均请输入：course\n");
            printf("若想按照课程计算平均请输入：student\n");
            ASK_FOR_INPUT()
            if(strcmp(buffer,"course")==0){
                flag=5;
            }
            else if(strcmp(buffer,"student")==0){
                flag=6;
            }
        }

        if(flag==5){
            //按课程计算均分
            printf("请输入你想计算的课程名\n");
            ASK_FOR_INPUT()
            int course_id = check_course_id(buffer);

            printf("%d",course_id);
            //debug_display_course_name_table(course_name_table);

            if(course_id==-1){
                printf("未找到您想查询的课程\n");
            }
            else{
                //数据保存无误，可能是courseid查询有问题
                //debug_show_course_score(course_id,course_score_table);
                double ans = cal_course_average_score(course_id,course_score_table,cur_course_number_of_stu[course_id]);
                printf("您想查询的%s课程平均成绩为%lf",course_name_table[course_id],ans);
            }
        }

        if(flag==6){
            //按学生计算均分
        }



        //printf("done\n");
        loop_counter++;

        //debug_show_course_score(0,course_score_table);
    }

    return 0;
}