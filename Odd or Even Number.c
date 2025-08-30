#include <stdio.h>

int main() {
    int n, i, num;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("%d is Even\n", num);
        else
            printf("%d is Odd\n", num);
    }

    return 0;
}
