typedef struct name{
    char first_name[15];
    char middle_name[15];
    char last_name[15];
} name;

typedef struct date_of_birth{
    int date;
    int month;
    int year;
} date_of_birth;

typedef struct student{
    int roll_number;
    name name;
    date_of_birth dob;
    int marks[3];
} student;

void read_students(student *students);
void display_studemts(student *students);