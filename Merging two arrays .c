#include <stdio.h>
int main() {
    int n1, n2, i, j, arr1[50], arr2[50], merge[100];
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements: ");
    for (i = 0; i < n1; i++) scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements: ");
    for (i = 0; i < n2; i++) scanf("%d", &arr2[i]);

    for (i = 0; i < n1; i++) merge[i] = arr1[i];
    for (j = 0; j < n2; j++) merge[i++] = arr2[j];

    printf("Merged Array: ");
    for (i = 0; i < n1+n2; i++) printf("%d ", merge[i]);
    return 0;
}
