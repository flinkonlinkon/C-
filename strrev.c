#include<stdio.h>
#include<string.h>

int main(){


    char name[100];
    char name1[100];

    // fgets(name,sizeof(name),stdin);
    gets(name);

    strcpy(name1,name);

    strrev(name1);


    if (strcmp(name,name1) == 0)
    {
        printf("ok");
    }else{
         printf("no");
    }
    


    return 0;

}