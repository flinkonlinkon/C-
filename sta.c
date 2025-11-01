#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

typedef struct Node * node;
typedef struct Node  nodes;

node top = NULL;

node push(node top,int data){
    node ptr =(node)malloc(sizeof(nodes));
    ptr->data=data;
    node temp = top;
    ptr->next=top;
    
    return ptr;
}

node pop(node top){
    node temp = top;
    top = top->next;
   
    free(temp);
    return top;
}

node peek(node top){
    while (top!=NULL)
    {
        printf("%d ->",top->data);
        top = top->next;
    }
    
}


int main(){

    top = push(top,23);
    top = push(top,24);
    top = push(top,25);
    top = push(top,26);

    top = pop(top);
    top = pop(top);
    top = pop(top);





    top = peek(top);



    return 0;
}
