#include<stdio.h>

int des(int n){
if(n==0) return 0;
printf("%d\n",n);
return des(n-1);
}

int main(){
int n;
scanf("%d",&n);
int num = des(n);
printf("%d\n",num);
return 0;

}
