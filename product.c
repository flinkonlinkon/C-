#include<stdio.h>

int main(){
int n, l;
scanf("%d",&n);
int sum =0;
for(int i=1;i<=n;i++){
    scanf("%d",&l);
    sum += l;


}
printf("%d",sum);
return 0;
}
