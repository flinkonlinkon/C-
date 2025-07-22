
#include <stdio.h>
#include <math.h>


int main() {

    double x1,x2,y1,y2,sum1,sum2,tsum;
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    sum1 = x2-x1;
    sum2 = y2-y1;

    tsum = (sum1*sum1)+(sum2*sum2);

    double fsum = sqrt(tsum);

    printf("%.4lf",fsum);



    return 0;
}
