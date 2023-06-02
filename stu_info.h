//未必要使用结构体？？

#define MAX_SIZE_OF_STU 1000
#define MAX_LENGTH 100
#include <string.h>

char stu_name_table[MAX_SIZE_OF_STU][MAX_LENGTH];
//double total_score_table[MAX_SIZE_OF_STU];//记录学生在各个课程的成绩

char course_name_table[MAX_LENGTH][MAX_LENGTH];
double course_score_table[MAX_LENGTH][MAX_SIZE_OF_STU];//记录学生课程成绩
int cur_course_number_of_stu[MAX_LENGTH];

#define INIT() for(int i=0;i<MAX_LENGTH;i++){\
        cur_course_number_of_stu[i]=0;\
        for(int j=0;j<MAX_SIZE_OF_STU;j++){\
            course_score_table[i][j]=-1;}}



double cal_course_average_score(int course_id,double course_score_table[MAX_LENGTH][MAX_SIZE_OF_STU]){
    double sum=0;
    int counter=0;
    //printf("%d",cur_course_number_of_stu);
    for(int i=0;i<MAX_SIZE_OF_STU;i++){
        if(course_score_table[course_id][i]!=-1){
            sum+=course_score_table[course_id][i];
            counter++;
        }
    }
    return (double)sum/counter;
}

double cal_stu_average_score(int stu_id,double course_score_table[MAX_LENGTH][MAX_SIZE_OF_STU]){
    double sum=0;
    double counter=0;
    for(int i=0;i<MAX_LENGTH;i++){
        if(course_score_table[i][stu_id]!=-1){
            sum+=course_score_table[i][stu_id];
            counter++;
        }
    }
    return sum/counter;
}

int has_stu_id(char buffer[MAX_LENGTH],char stu_name_table[MAX_SIZE_OF_STU][MAX_LENGTH]){
    for(int i=0;i<MAX_SIZE_OF_STU;i++){
        if(strcmp(buffer,stu_name_table[i])==0){
            return i;
        }
    }
    return -1;
}


int has_course_id(char buffer[MAX_LENGTH],char course_name_table[MAX_LENGTH][MAX_LENGTH]){
    for(int i=0;i<MAX_LENGTH;i++){
        if(strcmp(buffer,course_name_table[i])==0){
            return i;
        }
    }
    return -1;
}




