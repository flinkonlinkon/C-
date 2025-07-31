#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    double delta = (B * B) - (4 * A * C);

    if (delta < 0 || A == 0) {
        printf("Impossivel calcular\n");
    } else {
        double sqrt_delta = sqrt(delta);
        double R1 = (-B + sqrt_delta) / (2 * A);
        double R2 = (-B - sqrt_delta) / (2 * A);

        printf("R1 = %.5lf\n", R1);
        printf("R2 = %.5lf\n", R2);
    }

    return 0;
}
