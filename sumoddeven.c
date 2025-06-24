#include<stdio.h>

int main(){
int m[5] = {1,23,4,5,6};

int oddsum = 0;
int evensum = 0;
for(int i =0;i<=4;i++){
    if(m[i]%2==0) oddsum = oddsum + m[i];
    else evensum = evensum + m[i];
}
printf("%d\n",oddsum);
printf("%d\n",evensum);

return 0;
}
