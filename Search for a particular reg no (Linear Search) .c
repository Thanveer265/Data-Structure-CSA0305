#include <stdio.h>
int main() {
    int n, i, key, arr[50], found = 0;
    printf("Enter number of reg nos: ");
    scanf("%d", &n);
    printf("Enter reg nos: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter reg no to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Reg No %d found at position %d\n", key, i+1);
            found = 1;
            break;
        }
    }
    if (!found) printf("Reg No not found!\n");
    return 0;
}
