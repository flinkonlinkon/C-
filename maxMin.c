#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int max,min;
    int diff;
    for (int i=0;i<=n-1;i++){
        scanf("%d",&arr[i]);

    }
    max = min = arr[0];
    for(int i=0;i<=n-1;i++){
        if(arr[i]>max){
            max = arr[i];
        }
        else if(arr[i]<min){
            min = arr[i];
        }
    }
    diff = max - min;

    printf("%d\n%d\n%d\n",max,diff,min);

    return 0;
}
