
#include<stdio.h>
char* days_map[7]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int zellers(int date,int month, int year);
int main() {
    int date;
    printf("enter date : \n");
    scanf("%d",&date);
    int year;
    printf("enter year : \n");
    scanf("%d",&year);
    int month;
    printf("enter month : \n");
    scanf("%d",&month);

    const int answer = zellers(date,month,year);
    printf("%s",days_map[answer]);
    return 0;
}
int zellers(int date,int month, int year) {
    int new_year;
    int new_month;
    if (month==1) {
       new_month=  month+12;
        new_year = year-1;
    }else if(month ==2) {
        new_month = month+12;
        new_year = year-1;
    }else {
        new_year=year;
        new_month=month;
    }
    const int calc_year=new_year%100;
    const int calc_cen=new_year/100;
    const int form = date + (13 * (new_month + 1) / 5) + calc_year + (calc_year / 4) + (calc_cen / 4) - 2 * (calc_cen);
    printf("calculated day for  : %d  %d %d is \n",date ,month , year);
    const int result = form % 7;
    return result;
}