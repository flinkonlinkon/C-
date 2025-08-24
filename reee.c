#include<stdio.h>


int frrr(int n){

return n*frrr(n-1);

}

int main(){
int sum;
int n;
scanf("%d",&n);
for(int i =1;i<n;i++){

    sum = frrr(i);
    printf("%d\n",sum);
}


return 0;
}
