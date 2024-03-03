#include<stdio.h>
#include<stdlib.h>
/*Q.4*/

typedef struct time{
    int hour;
    int min;
    int sec;
}time;

/*Q.7*/

time add(time t1, time t2){
    time add;
    add.hour=t1.hour+t2.hour;
    add.min=t1.min+t2.min;
    add.sec=t1.sec+t2.sec; 
    return add;
}

time subtract(time t1, time t2){
    time diff;
    diff.hour=abs(t1.hour-t2.hour);
    diff.min=abs(t1.min-t2.min);
    diff.sec=abs(t1.sec-t2.sec); 
    return diff;
}

int main(){
    time start_time, end_time;
    printf("Enter start time in hr, min, sec\n");
    scanf("%d%d%d",&start_time.hour,&start_time.min,&start_time.sec);
    printf("Enter end time in hr, min, sec\n");
    scanf("%d%d%d",&end_time.hour,&end_time.min,&end_time.sec);
    while(start_time.hour<=end_time.hour){
        while(start_time.min<=end_time.min){
            while(start_time.sec<=end_time.sec){
                printf("Good Day\n");
                start_time.sec++;
            }
            start_time.min++;
        }
        start_time.hour++;
    }
    return 0;
}