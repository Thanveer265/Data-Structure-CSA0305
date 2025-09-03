#include <stdio.h>
int main() {
    int n, i, j, arr[50];
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Duplicate values: ");
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    return 0;
}
