struct student{
    int ID;
    char* s_name;
    double total_score;
    struct course c_list[50];
};

struct course
{
    char* c_name;
    float c_score;
};
