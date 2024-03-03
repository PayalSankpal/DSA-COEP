#include<stdio.h>
#include<string.h>
#include <ctype.h>

void toUpperCaseLib(char str1[]);
void toLowerCaseLib(char str1[]);
void toUpperCase(char str1[]);
void toLowerCase(char str1[]);


int main(){
    char str1[50];

    printf("Enter a string:\n");
    fgets(str1, sizeof(str1), stdin);
    if (str1[strlen(str1)-1]=='\n'){  //fgets adds newline charcter at end we remove that and add null character.
        str1[strlen(str1)-1]='\0';
    }
    printf("The string %s \n", str1 );
    toUpperCaseLib(str1);
    printf("in upper case is %s\n", str1);
    toLowerCaseLib(str1);
    printf("in lower case is %s\n", str1);
    toUpperCase(str1);
    printf("in upper case is %s\n", str1);
    toLowerCase(str1);
    printf("in lower case is %s\n", str1);

    return 0;
}

void toUpperCaseLib(char str1[50]){
    int i;
    for(i=0; str1[i]!='\0'; i++){
        if ('a' <= str1[i] <= 'z'){
            str1[i]=toupper(str1[i]);
        }
    }
}

void toLowerCaseLib(char str1[50]){
    int i;
    for(i=0; str1[i]!='\0'; i++){
        if ('A' <= str1[i] <= 'Z'){
            str1[i]=tolower(str1[i]);
        }
    }
}

void toUpperCase(char str1[]){
    int i;
    for(i=0; str1[i]!='\0'; i++){
        if (str1[i] >= 'a' && str1[i] <= 'z'){
            str1[i] -= 32;
        }
    }
}

void toLowerCase(char str1[]){
    int i;
    for(i=0; str1[i]!='\0'; i++){
        if ( str1[i] >= 'A' && str1[i] <= 'Z'){
            str1[i]= (str1[i] - 'A') + 'a';
        }
    }
}