#include<stdio.h>

int main(){

int n = 7;
int arr[n];

int sum=0;

for (int i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);

    if (arr[i]>=35)
    {
        sum++;
    }
    
}

if (sum>=3)
{
    printf("Wave");
}else{
    printf("No");
}




    return 0;
}