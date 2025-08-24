#include <stdio.h>
#include <string.h>

int main(){

   char name[20];

   printf("Enter a name:\n");
   gets(name);

   printf("You entered: \n");
   printf("%s", name);

   return 0;
}
