#include<stdio.h>

struct linkon
{
    int id;
    int roll;
    char name;
};



void main(){
    
// p1 = {21,765,"Linkon"};
// p1 = {12,445,"LEon"};

struct linkon p1 = {21,765,"Linkon"};



// p1.id = 23;
// p1.roll = 765;
// p1.name = "Linkon";

printf("%d %d %s",p1.id,p1.roll,p1.name);





}
