#include <stdio.h>

int main(){

int arr[20];
int tem;
for ( int i = 0;i<20;i++){
    scanf("%d",&arr[i]);
}

for ( int i = 0; i<10;i++){
   tem = arr[i];
   arr[i] = arr[19-i];
   arr[19-i] = tem;

}

for(int i = 0;i<20;i++){
    printf("N[%d] = %d\n", i, arr[i]);
}


return 0;
}
