#include<stdio.h>
typedef struct {
    int data;
    struct node *next;
}node;
int printlist(node *n) {
    while(n!=NULL) {
        printf(" %d ->",n->data);
        n = n->next ;
    }
    printf(" Null\n");
    return 0;

}
int main() {
    printf("basic self referential structure");
    node n1 = {1,NULL};
    node n2 = {2,NULL};
    node n3 = {3,NULL};
    n1.next = &n2;
    n2.next=&n3;
    printlist(&n1);

    return 0;
}
