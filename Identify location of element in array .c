#include <stdio.h>
int main() {
    int n, i, key, arr[50], found = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("Locations: ");
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) printf("Element not found!");
    return 0;
}
