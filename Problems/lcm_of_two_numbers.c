#include<stdio.h>

int lcm(int a , int b) {
    int max = a>b ? a: b;
    int lcm =max;
    while(lcm%a!=0 || lcm % b!=0) {
        lcm+=max;
    }
    return lcm;
}
int main() {
    int a = 840, b = 750;
    printf("%d",lcm(a,b));
    return 0;
}