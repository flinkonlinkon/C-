#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){

    

   char input[100];

   fgets(input,sizeof(input),stdin);

  

   for (int i = 0; input[i] !='\0'; i++)
   {
    char ch = tolower(input[i]);
    if (ch == 'a'|| ch == 'e' || ch == 'i'|| ch == 'o' || ch == 'u')
    {
       printf("*");
    }
    else{
        printf("%c",input[i]);
    }
    
   }
   




    return 0;
}