#include<stdio.h>

int main(){


int n;
scanf("%d",&n);
int max = -1;

int arr[n][n];

for (int i = 0; i < n; i++)
{
    for (int j = 0; i < n; j++)
    {
        scanf("%d",arr[i][j]);

        if (arr[i][j]> max)
        {
            max = arr[i][j];
        }
        
    }
    
}

printf("%d",max);

    return 0;
}