#include<stdio.h>

int stair(int n){
if (n == 1) {
        return 1;
    }


    if (n == 2) {
        return 2;
    }


    if (n == 3) {
        return 4;
    }
int way;
way = stair(n - 1) + stair(n - 2) + stair(n-3);


return way;
}

int main(){
int n;
scanf("%d",&n);
int way = stair(n);
printf("%d",way);
return 0;
}
