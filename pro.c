#include<stdio.h>

int main(){
float a,b,c,d;
scanf("%f %f %f %f",&a,&b,&c,&d);

float sum = a+b+c;
float per;
per = d/100;
float total = sum * per;

float newSum = sum - total;

printf("%.2f",newSum);
return 0;
}
