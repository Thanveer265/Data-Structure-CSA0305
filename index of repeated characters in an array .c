#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int i, j, n;
    printf("Enter a string: ");
    scanf("%s", str);
    n = strlen(str);

    printf("Repeated characters and their indices:\n");
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (str[i] == str[j]) {
                printf("%c at index %d and %d\n", str[i], i, j);
            }
        }
    }
    return 0;
}
