#include<stdio.h>
#include<string.h>

int string_length(char str[]);
void string_copy(char str2[], char str1[]);
int string_compare(char str1[], char str3[]);
void string_reverse(char str1[]);
void string_concat(char str1[], char str3[]);
void string_substring(char str1[], char substr[], int pos, int len);

int main(){
    char str1[100], str2[100], str3[100], substr[50];
    int i, result, pos, len;

    printf("Enter a string:\n");
    fgets(str1, sizeof(str1), stdin);
    if (str1[strlen(str1)-1]=='\n'){  //fgets adds newline charcter at end we remove that and add null character.
        str1[strlen(str1)-1]='\0';
    }
    printf("Enter another string:\n");
    fgets(str3, sizeof(str3), stdin);
    if (str3[strlen(str3)-1]=='\n'){  //fgets adds newline charcter at end we remove that and add null character.
        str3[strlen(str3)-1]='\0';
    }
    

    printf("Using lib, the length of first string is %d\n", strlen(str1));
    printf("Without using lib, the length of first string is %d\n", string_length(str1));

    strcpy(str2, str1);
    printf("Using lib, the copy of first string is %s\n", str2);
    string_copy(str2,str1);
    printf("Without using lib, the copy of first string is %s\n", str2);

    result=strcmp(str1, str3);
    printf("Using library\n");
    if (result == 0){
        printf("The two strings are equal.\n");
    }
    else if (result > 0){
        printf("The first string is greater than second.\n");
    }
    else if (result < 0){
        printf("The second string is greater than first.\n");
    }

    result=string_compare(str1, str3);
    printf("Without using library\n");
    if (result == 0){
        printf("The two strings are equal.\n");
    }
    else if (result > 0){
        printf("The first string is greater than second.\n");
    }
    else if (result < 0){
        printf("The second string is greater than first.\n");
    }

    strrev(str1);
    printf("Using lib, the copy of reverse string is %s\n", str1);
    string_reverse(str1);
    string_reverse(str1);
    printf("Without using lib, the reverse of first string is %s\n", str1);

    strcat(str2, str3);
    printf("Using lib, the concated string is %s\n", str2);
    string_reverse(str1);
    string_concat(str1,str3);
    printf("Without using lib, the concated string is %s\n", str1);

    printf("Enter pos and len of substring from string %s:\n", str1);
    scanf("%d%d", &pos, &len);
    string_substring(str1, substr, pos, len);
    printf("The substring is %s\n", substr);

    return 0;
}

int string_length(char str[]){
    int i;
    for(i=0; str[i]!='\0'; i++){
        ;
    }
    return i;
}

void string_copy(char str2[], char str1[]){
    int i;
    for(i=0; str1[i]!='\0'; i++){
        str2[i]=str1[i];
    }
    str2[i+1]='\0';
}

int string_compare(char str1[], char str3[]){
    int i,j;
    for(i=0; str1[i]!='\0' || str3[i]!='\0'; i++){
        if (str1[i]!=str3[i]){
            return str1[i]-str3[i];
        }
    }
    return str1[i]-str3[i];
}

void string_reverse(char str1[]){
    int i, j, temp;
    for(i=0; str1[i]!='\0'; i++){
        temp=str1[0];
        for(j=1; str1[j+i]!='\0'; j++){
            str1[j-1]=str1[j];
        }
        str1[j-1]=temp;
    }
}

void string_concat(char str1[], char str3[]){
    int i;
    int len=strlen(str1);
    for(i=0; str3[i]!='\0'; i++){
        str1[len+i]=str3[i];
    }
    str1[len+i]='\0';
}

void string_substring(char str1[], char substr[], int pos, int len){
    int i;
    for(i=pos-1; i<len+pos-1 && str1[i]!='\0'; i++){
        substr[i-(pos-1)]=str1[i];
    }
    substr[len]='\0';
}
