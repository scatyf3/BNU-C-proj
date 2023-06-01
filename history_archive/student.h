#define MAX_SIZE_OF_STU 10000
#define MAX_LENGTH 100

struct course
{
    char c_name[MAX_SIZE];
    float c_score;
};


struct student{
    int ID;
    char s_name[MAX_SIZE];
    double total_score;
    struct course c_list[50];
};

