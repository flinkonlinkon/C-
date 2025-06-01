#include <stdio.h>

int main() {

    int A,B,C,D,sumF,sumL,DIFERENCA;

    scanf("%d %d %d %d",&A,&B,&C,&D);

    sumF = A*B;
    sumL = C*D;

    DIFERENCA = sumF-sumL;

    printf("DIFERENCA = %d\n",DIFERENCA);


    return 0;
}
