//未必要使用结构体？？

#define MAX_SIZE_OF_STU 1000
#define MAX_LENGTH 100
#include <string.h>

//student info
//student id = index of array
int number_of_stu = 0;
char stu_name_table[MAX_SIZE_OF_STU][MAX_LENGTH];
double total_score_table[MAX_SIZE_OF_STU];

//course info
int number_of_course = 0;
char course_name_table[MAX_LENGTH][MAX_LENGTH];
double course_score_table[MAX_LENGTH][MAX_SIZE_OF_STU];


int check_stu_id(char stu_name[MAX_LENGTH]){
    //返回学生姓名对应的id，-1对应着查询失败
    int stu_id;
    for(int i=0;i<number_of_stu;i++){
        if(stu_name==stu_name_table[i]){
            stu_id=i;
        }
        else{
            return -1;
        }
    }
}

int check_course_id(char course_name[MAX_LENGTH]){
    //返回学生姓名对应的id，-1对应着查询失败
    int course_id;
    for(int i=0;i<number_of_course;i++){
        if(course_name==stu_name_table[i]){
            course_id=i;
        }
        else{
            return -2;
        }
    }
}

double check_total_score(char stu_name[MAX_LENGTH]){
    int stu_id = check_stu_id(stu_name);
    if(stu_id == -1){
        return -1;
    }
    return total_score_table[stu_id];
}

double check_course_score(char stu_name[MAX_LENGTH],char course_name[MAX_LENGTH]){
    int stu_id = check_stu_id(stu_name);
    if(stu_id == -1){
        return -1;
    }
    int course_id = check_course_id(course_name);
    if(course_id == -2){
        return -2;
    }
    return course_score_table[course_id][stu_id];
}



