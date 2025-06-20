#include<stdio.h>

void sum (int x , int t){

if(x==0){
    printf("%d",t);
    return;
}

sum(x-1,x+t);
return;

}

int main(){
int n,t;
scanf("%d, %d",&n,&t);
sum(n,t);
return 0;

}
