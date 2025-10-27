#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node;

void mal(node *x){
    while (x !=NULL)
    {
        printf("%d  ",x->data);
       x = x->next;
    }
    
}


int main(){

    node *p1,*p2,*p3;

    p1 = (node*)malloc(sizeof(node));
    p2 = (node*)malloc(sizeof(node));
    p3 = (node*)malloc(sizeof(node));


    p1->data =12;
    p1->next =p2;
    p2->data =15;
    p2->next =p3;
    p3->data =19;
    p3->next =NULL;

    mal(p1);
    


    return 0;
}