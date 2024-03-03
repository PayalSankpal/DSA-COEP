#include<stdio.h>
/*Q.6*/
typedef struct date{
    int day;
    int month;
    int year;
}date;

int isLeapYear(int year){
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int valid_date(date d1){
    int valid = 1;
    if(d1.month<1 || d1.day>12){
        valid=0;
    }
    else if(d1.month==1 || d1.month==3 || d1.month==5 || d1.month==7 || d1.month==8 || d1.month==10 || d1.month==12){
        if(d1.day>31 || d1.day<1){
            valid = 0;
        }
    }
    else if(d1.month==2){
        if(isLeapYear(d1.year)){
            if(d1.day>29 || d1.day<1){
                valid=0;
            }
        }
        else{
            if(d1.day>28 || d1.day<1){
                valid =0;
            }
        }
    }
    else{
        if(d1.day>30 || d1.day<1){
            valid = 0;
        }
    }
    return valid;
}

int main(){
    date d1;
    printf("Enter Date as day month year.\n");
    scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
    int valid = valid_date(d1);
    (valid==1) ? printf("Its valid\n") : printf("Its invalid!\n");
    return 0;
}