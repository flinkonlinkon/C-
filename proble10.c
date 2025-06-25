#include<stdio.h>

int main() {
    int code1, qty1, code2, qty2;
    float price1, price2;


    scanf("%d %d %f", &code1, &qty1, &price1);


    scanf("%d %d %f", &code2, &qty2, &price2);

    float total = (qty1 * price1) + (qty2 * price2);

    printf("VALOR A PAGAR: R$ %.2f\n", total);

    return 0;
}
