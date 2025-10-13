#include<stdio.h>
#include<string.h>

struct nam{
    int id;
    char name[20];
    float price;
} a,b;

int main(){
    scanf("%d",&a.id);
    fgets(a.name,sizeof(a.name),stdin);



printf("%d",a.id);
printf("%s",a.name);

    
    
    return 0;
}