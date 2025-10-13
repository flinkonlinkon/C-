#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    if (n>=40)
    {
        printf("Barie");
    }else if(n>=30 && n<40){
        printf("shabdhane");
    }else if (n<30)
    {
        printf("Jabe");
    }
    
    
    return 0;
}