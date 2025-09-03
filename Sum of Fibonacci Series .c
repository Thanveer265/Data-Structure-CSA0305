#include <stdio.h>
int main() {
    int n, i, a = 0, b = 1, c, sum = 0;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", a);
        sum += a;
        c = a + b;
        a = b;
        b = c;
    }
    printf("\nSum = %d\n", sum);
    return 0;
}
