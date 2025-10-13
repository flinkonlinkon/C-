// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int main() {
    char nam1 [15];
    char nam2 [15];
    
    printf("Name 1:");
    fgets(nam1);
    printf("Name 2:");
    fgets(nam2);
    
    if(strcmp(nam1,nam2)){
        printf("right");
    } else{
    printf("Try programiz.pro");    
    }
    

    return 0;
}