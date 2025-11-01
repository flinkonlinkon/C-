#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

typedef struct Node * node;
typedef struct Node  nodes;

node firstInsert(node head,int data){
    node ptr =(node)malloc(sizeof(nodes));
    node temp = head;
    ptr->data = data;

    ptr->next=temp;

    return ptr;
}

node randomInsert(node head,int ind,int data){
    node ptr =(node)malloc(sizeof(nodes));
    node temp =head;

    for (int i = 1; i < ind-1; i++)
    {
        temp = temp->next;
    }

    ptr->data = data;
    ptr->next=temp->next;
    temp->next= ptr;

    return head;
    
}

node endInsert(node head,int data){
    node ptr =(node)malloc(sizeof(nodes));
    node temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    ptr->data=data;
    ptr->next=NULL;
    temp->next=ptr;
    return head;
    
}

node delF(node head){
    node temp = head;
    head = head->next;
    free(temp);
    return head;
}

node delRandom(node head,int ind){
    node temp = head;

for (int i = 1; i < ind-1; i++)

{
    temp = temp->next;
}

    node del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

node delE(node head){
    node temp = head;
    while (temp->next->next!=NULL)
    {
        temp =temp->next;
    }

    temp->next=NULL;
    free(temp->next);
    return head;
    
}

node display(node head){
    while (head!=NULL)
    {
        printf("%d ->",head->data);
        head = head->next;

    }
    
}



int main(){
node head = (node)malloc(sizeof(nodes));
node h1 = (node)malloc(sizeof(nodes));
node h2 = (node)malloc(sizeof(nodes));
node h3 = (node)malloc(sizeof(nodes));

head->data=10;
h1->data=20;
h2->data=30;
h3->data=40;

head->next=h1;
h1->next=h2;
h2->next=h3;
h3->next=NULL;

head = firstInsert(head,19);
head = randomInsert(head,2,88);
head = endInsert(head,56);
head = delF(head);
head = delRandom(head,2);
head = delE(head);
head = display(head);


    return 0;

}