#include <stdio.h>

int main() {

    double R;
    scanf("%lf",&R);
    double sum;

    sum =  (4.0/3)*3.14159 *R*R*R;

    printf("VOLUME = %.3lf\n",sum);

    return 0;
}
