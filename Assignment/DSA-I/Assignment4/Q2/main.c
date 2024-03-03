#include<stdio.h>
#include"header.h"
#include"logic.c"

int main(){
    student students[5];
    read_students(students);
    display_students(students);
    return 0;
}