#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("Ho!");
        else
            printf("Ho ");
    }

    return 0;
}
