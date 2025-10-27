#include <stdio.h>
#include <stdlib.h>
int count=0;
struct Node{
    int data;
    struct Node * next;
};

typedef struct Node * node;
typedef struct Node  Nodes;

node fristIns(node head,int data){
    node news = (node)malloc(sizeof(struct Node));
    news->data = data;
    news->next = head;
    return head;
}

node end(node head,int data){
    
    node news =(node)malloc(sizeof(Nodes));
    news->data = data;
    news->next = NULL;
    
    node temp = head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next = news;
    return head;
    
    
}

node middle(node head,int ind,int data){
    node news = (node)malloc(sizeof(Nodes));
    news->data = data;
    
    node temp = head;
    
   
    
     for (int i = 1; i < ind - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
     news->next = temp->next;
    temp->next =news;
    return head;
    
    
}

node delF(node head){
//     node temp = head;
//   head= head->next ;
//     free(temp);
//     return head;
node temp = head;
    head = head->next;  
    free(temp);         
    return head;
    
    
}

node delE(node head){
    node temp = head;

    while(temp->next->next !=NULL){
        temp = temp->next;
    }
    
    free(temp->next);
    temp->next =NULL;
    return head;
}

node delM(node head,int ind){
    
    node temp = head;
    for(int i =1;i<ind-1;i++){
        temp = temp->next;
    }
    
    node del = temp->next;
    temp->next = del->next;
    free(del);
}

void display(node head){
    
    while(head!=NULL){
        
        printf("%d ->",head->data);
      head =  head->next;
      count++;
      
    }
     printf("count :%d\n",count);
 
}

int main() {
   
    node head =(node)malloc(sizeof(struct Node));
    node h1 =(node)malloc(sizeof(struct Node));
    node h2 =(node)malloc(sizeof(struct Node));
    node h3 =(node)malloc(sizeof(struct Node));
    node h4 =(node)malloc(sizeof(struct Node));
    
    printf("%p head\n",head);
    printf("%p next\n",head->next);
    
    head->data =1;
    h1->data=10;
    h2->data=20;
    h3->data=30;
    h4->data=40;
  
    
    head->next = h1;
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = NULL;
    
    // head = fristIns(head,99);
    printf("%p head\n",head);
    printf("%p next\n",head->next);
    // head = fristIns(head,199);
    printf("%p head\n",head);
    printf("%p next\n",head->next);
    end(head,89);
    middle(head,5,2256);
    delE(head);
    delM(head,2);
//   head = delF(head);
    display(head);
    
    return 0;
}