#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * insert(struct node *p1,int data){
    struct node * prt =(struct node *)malloc(sizeof(struct node));
 
    prt->data = data;
       prt->next = p1;
    return prt;
}

struct node * del(struct node * x){
    struct node * ptr = x;
    x =  x->next;
    
    free(ptr);
    return x;
}

struct node * display(struct node * x){
    while(x != NULL){
    printf("%d  ->",x->data);
    x = x->next;
    }
}

int main(){
    
    struct node *p1,*p2,*p3;
    
    p1 =(struct node*)malloc(sizeof(struct node));
    p2 =(struct node*)malloc(sizeof(struct node));
    p3 =(struct node*)malloc(sizeof(struct node));
    
    p1->data =2;
    p2->data =3;
    p3->data =5;
    
    p1->next=p2;
    p2->next=p3;
    p3->next=NULL;
    
// p1 =    insert(p1,78);
p1 =    del(p1);
    
    display(p1);
    return 0;
}