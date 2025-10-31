// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

typedef struct Node * node;
typedef struct Node  nodes;

node fIn(node head,int data){

    node ptr =(node)malloc(sizeof(nodes));

    node temp = head;
    
    ptr->data=data;

    temp->prev=ptr;
    ptr->prev=NULL;
    ptr->next=temp;

    return ptr;

}

node indIn(node head,int ind,int data){
    node ptr =(node)malloc(sizeof(nodes));

    ptr->data=data;
    node temp=head;

    for(int i=1;i<ind-1;i++){
        temp=temp->next;

     
    }

    ptr->next=temp->next;
    temp->next=ptr;

    ptr->prev=temp;
   

    return temp;
}

node endIn(node head,int data){

    node ptr =(node)malloc(sizeof(nodes));
    node temp = head;
    ptr->data =data;

    while (temp->next !=NULL)
    {
        temp = temp->next;
    }

    ptr->next=NULL;
    ptr->prev=temp;

    temp->next=ptr;

    return head;
    
    
    
}

node fDel(node head){
    node temp =head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

node indDel(node head,int ind){
    node temp = head;

    for (int  i = 1; i < ind-1; i++)
    {
        temp = temp->next;
    }
    
   node delNode = temp->next;

   temp->next = delNode->next;

   free(delNode);
   return head;

    
}

node endDel(node head){

    node temp = head;

    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
temp->prev->next = NULL;
    free(temp);
    return head;
    

}

void display(node head){
    
    while(head!=NULL){
        printf("%d ->",head->data);
        head = head->next;
    }
}


int main() {
    

    node head =(node)malloc(sizeof(nodes));
    node h1 =(node)malloc(sizeof(nodes));
    node h2 =(node)malloc(sizeof(nodes));
    node h3 =(node)malloc(sizeof(nodes));
    node h4 =(node)malloc(sizeof(nodes));
    
    head->data = 21;
    h1->data = 22;
    h2->data = 26;
    h3->data = 27;
    h4->data = 29;
    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = NULL;
    head->prev=NULL;
h1->prev=head;
h2->prev=h1;
h3->prev=h2;
h4->prev=h3;

head = fIn(head,45);
head =indIn(head,2,78);
head = endIn(head,88);
head = fDel(head);
indDel(head,2);
head = endDel(head);
display(head);
    return 0;
}