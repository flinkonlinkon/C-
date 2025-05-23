#include <stdio.h>

void reminder(){

int big,small;

printf("The big number input:\n");
printf("The small number input:\n");
scanf("%d %d",&big,&small);

int q = big/small;

int re = big - (q*small);
printf("The reminder is : %d",re);

}

void fraction(){
    float a;
printf("Enter the number : ");
scanf("%f",&a);

int ab = a;

float fr = a -  ab;

printf("The fraction number is : %f", fr);


}

int main (){

float r = 3;

float area = 3.14 * r*r;
//printf("%f",area);

fraction();

//reminder();
return 0;
}




