void debug_show_course_score(int course_id,double course_score_table[MAX_LENGTH][MAX_SIZE_OF_STU]){
    for(int i=0;i<10;i++){
        //便利起见只循环到10
        printf("%lf",course_score_table[course_id][i]);
    }
}
    
void debug_display_cur_counter(int course_counter,int student_counter){
    printf("course_counter=%d,student_counter=%d",course_counter,student_counter);
}

void debug_display_course_name_table(char course_name_table[MAX_LENGTH][MAX_LENGTH]){
    for(int i=0;i<MAX_LENGTH;i++){
        printf("%s",course_name_table[i]);
    }
}