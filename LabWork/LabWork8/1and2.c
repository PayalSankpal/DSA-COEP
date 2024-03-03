#include<stdio.h>

/*Q1*/
typedef struct name{
    char *fname;
    char *mname;
    char *lname;
}name;

typedef struct date{
    int day;
    int month;
    int year;
}date;

typedef struct marks{
    int English;
    int Maths;
    int ComputerScience;
}marks;

typedef struct Student{
    int RollNumber;
    name Name;
    char gender;
    date DOB;
    marks Marks;
}Student;

int main(){
    char *name;
    Student Students[10];
    Students[0].RollNumber=1;
    Students[0].Name.fname="Amy";
    Students[0].Name.mname="Farrah";
    Students[0].Name.lname="Fowler";
    Students[0].gender='F';
    Students[0].DOB.day=12;
    Students[0].DOB.month=12;
    Students[0].DOB.year=2004;
    Students[0].Marks.English=96;
    Students[0].Marks.ComputerScience=96;
    Students[0].Marks.Maths=96;

    // Set values for the second student
    Students[1].RollNumber = 2;
    Students[1].Name.fname = "Amy";
    Students[1].Name.mname = "Jane";
    Students[1].Name.lname = "Smith";
    Students[1].gender = 'F';
    Students[1].DOB.day = 5;
    Students[1].DOB.month = 8;
    Students[1].DOB.year = 2003;
    Students[1].Marks.English = 85;
    Students[1].Marks.ComputerScience = 92;
    Students[1].Marks.Maths = 88;

    // Set values for the third student
    Students[2].RollNumber = 3;
    Students[2].Name.fname = "John";
    Students[2].Name.mname = "William";
    Students[2].Name.lname = "Doe";
    Students[2].gender = 'M';
    Students[2].DOB.day = 18;
    Students[2].DOB.month = 4;
    Students[2].DOB.year = 2002;
    Students[2].Marks.English = 22;
    Students[2].Marks.ComputerScience = 25;
    Students[2].Marks.Maths = 15;

    printf("Enter name of student:\n");
    scanf("%s",name);
    for(int i=0; i<3; i++){
        if(*(Students[i].Name.fname)==(*name)){
            printf("Rollnumber: %d\n",Students[i].RollNumber);
            printf("Name:%s %s %s\n",Students[i].Name.fname,Students[i].Name.mname,Students[i].Name.lname);
            printf("Gender:%c\n",Students[0].gender);
            printf("DOB:%d/%d/%d\n",Students[0].DOB.day,Students[0].DOB.month,Students[0].DOB.year);
            printf("Marks: English:%d Maths:%d CS:%d\n",Students[0].Marks.English,Students[0].Marks.Maths,Students[0].Marks.ComputerScience);
        }
    }

    for (int i = 0; i < 3; ++i) {  
        float averageMarks = (Students[i].Marks.English+Students[i].Marks.Maths+Students[i].Marks.ComputerScience)/3;
        float aggregatePercentage = averageMarks;

        printf("Student %s %s %s has an average of %.2f%% marks\n",
                   Students[i].Name.fname, Students[i].Name.mname, Students[i].Name.lname, averageMarks);

        if (aggregatePercentage < 40) {
            printf("Student %s %s %s (Roll Number %d) has an average of %.2f%% marks and has secured less than 40%% aggregate.\n",
                   Students[i].Name.fname, Students[i].Name.mname, Students[i].Name.lname,
                   Students[i].RollNumber, averageMarks);
        }
    }
    return 0;
}