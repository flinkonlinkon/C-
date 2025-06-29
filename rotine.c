#include<stdio.h>

int main(){
int sum = 0;
int arr[7];
float av;
int day = 0;
int count = 0;

for(int i = 0; i<7;i++){

    scanf("%d ",&arr[i]);
    sum = sum + arr[i];
    if(arr[i] >30){
        count = i;
        day = i + 1;

printf("%d",day);

    }
}

av = sum/7;

printf("Av is %.2f\n %d\n",av, count);

return 0;

}
