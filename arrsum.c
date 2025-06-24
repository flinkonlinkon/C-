#include<stdio.h>

int main(){
int n;
scanf("%d",&n);
int arr[n];

for (int i = 0;i<=n-2;i++){
    scanf("%d",&arr[i]);
}

 int sum = 0;
for(int i=0;i<=n-1;i++){

        printf("%d\n",i);

     sum = arr[i] + sum;

}
printf("sum is : %d\n",sum);

return 0;
}
