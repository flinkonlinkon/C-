#include <stdio.h>
int main() {
    int a=5, b=10;
    int *x, *y;
    x = &a;
    y = &b;
    *x = *x + a;   // a = 5+10 = 15
    *y = *y + b;   // b = 15+10 = 25

    printf("a=%d b=%d\n", *y+a, b);
    printf("*x=%d *y=%d\n", *x, a+*y);
    return 0;
}
