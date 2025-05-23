#include <stdio.h>

int main() {
    char linkon[10001];

    printf("Hi buddy. Do you want something?\n");

    scanf("%s", linkon);

    printf("%s is a very good product. Do you want to buy this?\n", linkon);

    scanf("%s", linkon);

    printf("Thank you for everything.\n");

    return 0;
}
