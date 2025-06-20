#include<stdio.h>

int main (){

int n;
scanf("%d",&n);

int nst = n;
int nsp = 1;
for(int i=1;i<=n*2 +1;i++){
    printf("*");
}
printf("\n");
for(int i =1;i<=n;i++){

    for(int k=1;k<=nst;k++){
        printf("*");
    }

    for(int j=1;j<=nsp;j++){
        printf("#");
    }

    for(int k=1;k<=nst;k++){
        printf("*");
    }
    nst --;
    nsp +=2;

    printf("\n");
}
for(int i=1;i<=n*2 +1;i++){
    printf("*");
}



return 0;
}
