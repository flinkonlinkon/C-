#include <stdio.h>

int main (){

int n,x;
printf("Enter the number of star and line : ");
scanf("%d %d",&n,&x);
for(int i=1;i<=x;i++){
for(int i=1;i<=n;i++){
    printf("*");
}
printf("\n");
}


return 0;
}
