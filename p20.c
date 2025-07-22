#include <stdio.h>

int main() {

   int a,b,c;
   scanf("%d",&a);

   b = a/365;

   c = a - (b*365);

   int m = c/30;

   int d = c - (m*30);

   printf("%d ano(s)\n",b);
   printf("%d mes(es)\n",m);
   printf("%d dia(s)\n",d);

    return 0;
}
