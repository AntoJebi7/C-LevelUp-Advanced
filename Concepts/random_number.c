//
// Created by antoa on 02-02-2025.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(0));
    printf("%d",rand()%6+1);
    return 0;
}
