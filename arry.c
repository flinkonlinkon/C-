#include<stdio.h>

int main(){
int arr[10] = {66,44,55,22,66,44,99,77,55,88};

for(int i=0;i<=9;i++){
    if(arr[i]<50){
        printf("%d\n",arr[i]);
    }
}

}

