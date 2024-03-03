void read_students(student *students){
    int i;
    for (i=0; i<5; i++){
        printf("Student %d\n", i+1);
        printf("Enter roll number: \n");
        scanf("%d",&students[i].roll_number);
        printf("Enter student\'s name (First_name Middle_name last_name)\n");
        scanf("%s%s%s",&students[i].name.first_name, &students[i].name.middle_name, &students[i].name.last_name);
        printf("Enter date of birth (day month year)\n");
        scanf("%d%d%d", &students[i].dob.date, &students[i].dob.month, &students[i].dob.year);
        printf("Enter marks of Eng Maths and CS:\n");
        scanf("%d%d%d", &students[i].marks[0],&students[i].marks[1], &students[i].marks[2]);
    }
}

void display_students(student *students){
    int i;
    for (i=0; i<5; i++){
        int avg_marks =  (students[i].marks[0]+students[i].marks[1]+students[i].marks[2])/3;

        printf("%c",'\n');

        printf("Student %d\n", i+1);
        printf("Roll number: %d\n",students[i].roll_number);
        printf("Name: %s %s %s\n",students[i].name.first_name, students[i].name.middle_name, students[i].name.last_name);
        printf("Date of Birth: %d/%d/%d\n", students[i].dob.date, students[i].dob.month, students[i].dob.year);
        printf("Marks:- Eng:%d Maths:%d CS:%d\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("Average Marks: %d\n",avg_marks);
    }
}
