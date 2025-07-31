#include<stdio.h>

int main(){

float n,a;
scanf("%f",&n);
float sum = 0;
if (n>0 && n<=400){

    a = n * 0.15;
    sum = a + n;
    printf("Novo salario: %.2f\n",sum);
    printf("Reajuste ganho: %.2f\n",a);
    printf("15 %%\n");
} else if(n>400.01 && n<=800){
a = n * 0.12;
    sum = a + n;
    printf("Novo salario: %.2f\n",sum);
    printf("Reajuste ganho: %.2f\n",a);
    printf("12 %%\n");

} else if(n>800.01 && n<=1200){
a = n * 0.10;
    sum = a + n;
    printf("Novo salario: %.2f\n",sum);
    printf("Reajuste ganho: %.2f\n",a);
    printf("10 %%\n");

} else if(n>1200.01 && n<=2000){
a = n * 0.07;
    sum = a + n;
    printf("Novo salario: %.2f\n",sum);
    printf("Reajuste ganho: %.2f\n",a);
    printf("7 %%\n");

} else if(n>2000){
a = n * 0.04;
    sum = a + n;
    printf("Novo salario: %.2f\n",sum);
    printf("Reajuste ganho: %.2f\n",a);
    printf("4 %%\n");

}

return 0;
}
