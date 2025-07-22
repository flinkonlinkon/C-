#include<stdio.h>
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: F(0) = 0, F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive step
    }
}
int main(){

int count;

    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &count);

    if (count < 0) {
        printf("Please enter a non-negative number.\n");
    } else {
        printf("Fibonacci Series:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
    return 0;
}
