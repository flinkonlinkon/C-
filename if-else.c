#include <stdio.h>

void staightLine(){

double x1,x2,x3,y1,y2,y3;

printf("Enter the point x1,x2,x3,y1,y2,y3");

scanf("%d %d %d %d %d %d",&x1,&x2,&x3,&y1,&y2,&y3);

double m1 = (y2-y1)/(x2-x1);

double m2 = (y3-y2)/(x3-x2);

if(m1==m2){

    printf("StaightLine\n %d",m1);
}else{
printf("not StaightLine\n %d %d",m1,m2);
}








}


void check(){

int a=3;
float b=3.00;

if(a==b) printf("right\n");
else printf("wrong\n");



}




void cnum(){
int a;
scanf("%d",&a);
if (99<a && a<1000){

    printf("Righht\n");
}else{

printf("wrong\n");
}

}




void triangle(){
int l,b;

scanf("%d %d",&l,&b);

int a= l*b;
int p = 2*(l+b);
if(a>p){
    printf("Area big");
}
if(p>a){
    printf("Parameter big");

}

if(a==p){
    printf("Both same");
}



}

void input(){
int c,s;

printf("Input the cost and sell price");

scanf("%d %d",&c,&s);

if(s>c){
    int sum = s-c;
    printf("The profite is : %d\n",sum);


}else{
int lose = c-s;
printf("The lose is :%d\n",lose);

}
}

void absolute(){

int x;

printf("enter the number : ");

scanf("%d",&x);

if(0>x){

    int sum = x*(-1);

    printf("Number:%d\n",sum);
}else{
printf("Number:%d\n",x);
}



}

void leaperYear(){

int year;

printf("Enter The Year : ");

scanf("%d",&year);

if(year%4 == 0){

printf("It is leaper Year\n");

}else{
printf("It is not leaper year\n");

}

}



int main(){

    check();

    //absolute();

   // leaperYear();

int a;

//printf("Enter The Number : ");

//scanf("%d",&a);
int sum = a/5;


if( sum%2 == 0){
    printf("right");
}else{
printf("wrong");
}

return 0;

}
