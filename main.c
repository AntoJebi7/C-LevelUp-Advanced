#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int* add(int *a , int *b);
int greet();
int subt(int a, int b);
int callsubtr(int (*ptr)());
void bubble_sort(int* arr,int n, int (*compare)(int a, int b));
int compare(int a, int b);




int cash = 100;
void Play(int bet) {
    char *arr = (char*)malloc(3*sizeof(char));
    arr[0]='J';arr[1]='Q';arr[2]='K';
    printf("Shuffling.... \n");
    srand(time(NULL));
    int i;
    for(i=0;i<5;i++) {
        int x = rand()%3;
        int y = rand()%3;
        int temp = arr[x];
        arr[x]=arr[y];
        arr[y]=temp;
    }
    int playerGuess;
    printf("guess the position of queen , 1or2or3 ?\n");
    scanf("%d",&playerGuess);
    if(arr[playerGuess-1]=='Q') {
        cash+= 3*bet;
        printf("your cash will be awarded 3 x bet times\n");
        printf("You win ! result = %c %c %c Total cash = %d",arr[0],arr[1],arr[2],cash);

    }else {
        cash -=bet;
        printf("You Lose ! result = %c %c %c Total cash = %d",arr[0],arr[1],arr[2],cash);

    }
    free(arr);
}



int main(void) {
    /*
    * int threed[2][3][3] ={{{1,2,3},  //0th row j
                             {4,5,6},  //1st row j
                             {7,8,9}},  // 2nd row j

                            {{11,12,13},
                                {14,15,16},
                                {17,18,19}}
    };
    int (*ptr)[3][3]= threed;
    printf("%d",*(*(*(ptr+1)+2)+1));      // *(*(*(block)row)column)

    int *arr = (int*) malloc(5 * sizeof(int));

    if(arr==NULL) {
        printf("Aloocation failed");
    }else {
        printf("garbage value %d\n",*arr);
        for(int i=0;i<5;i++) {
            arr[i]=i;
            printf("%d",arr[i]);
        }
    }
    printf("\n");
    arr = (int*) realloc(arr,10 *sizeof(int));
    for(int i=0;i<10;i++) {
        arr[i]=i;
        printf("%d",arr[i]);
    }
    free(arr);
    int a=90,b=100;
    int *c = add(&a,&b);
    greet();
    printf("sum = %d\n",*c);
    printf("main , a = %d  b = %d",a,b);
    free(c);
    int (*p)(int,int);
    p=subt;
    int difff;
    difff = p(6,9);
    printf("%d\n",difff);

    int (*ptr)() = greet;
    callsubtr(ptr);  // or callsubtr(greet)
    int i=0;
    int arr[]={56,23,670,2,43,68,3,67,98};
    int size = sizeof(arr)/sizeof(arr[i]);
    bubble_sort(arr,size,compare);
    for(i=0;i<size;i++) {
        printf("%d\t",arr[i]);
    }
     */
    int bet;
    while(cash > 0) {
        printf("Whats your bet :");
        scanf("%d",&bet);
        if(bet==0 || bet > cash) break;
        Play(bet);
    }



    return 0;
}





int compare(int a,int b) {
    if(a>b) return 1;
    else return -1;
}
void bubble_sort(int *arr,int n, int (*compare)(int , int )) {
    int i,j,temp;
    for(i=0;i<n;i++) {
        for(j=0;j<n-1;j++) {
            if(compare(arr[j],arr[j+1])>0) {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}





int callsubtr(int (*ptr)()) {
    ptr();
}
int greet() {
    printf("Hello\n");
    return 0;
}
int* add(int* a,int* b) {
    int p = *a + 10;
    int q= *b +10;
    int* sum = (int*)malloc(sizeof(int));
    *sum = (*a) + (*b);
    *a = p;
    *b = q;
    return sum;
}
int subt(int a, int b) {
    return a-b;
}