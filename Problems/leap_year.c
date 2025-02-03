#include<stdio.h>

int main() {
    int year;
    printf("Enter the Year : \n");
    scanf("%d",&year);
    if(year%4==0) {
        if(year%100!=0) {
            printf("leap year");
        }else if(year%400==0) {
            printf("leap year");
        }else {
            printf("not leap year");
        }
    }else {
        printf("Not a leap year\n");
    }
    return 0;
}