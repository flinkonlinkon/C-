#include<stdio.h>


int res(int n){

if(n == 0) return 0;

else if(n==1) return 1;

return res(n-1) + res (n-2);



}

int main(){

int n;

scanf("%d",&n);

int sum = res(n);

printf("%d\n",sum);


return 0;
}
