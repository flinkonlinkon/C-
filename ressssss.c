#include<stdio.h>


int res(int n){

if(n==0){
    return 0;
} else if(n==1){

return 1;
}

return res(n-1)+res(n-2);

}

int main(){

int n;

scanf("%d",&n);

for(int i=0;i<n;i++){

    printf("%d\n",res(i));
}

return 0;
}
