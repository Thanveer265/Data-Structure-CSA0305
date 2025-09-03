#include <stdio.h>
int main() {
    int arr[50], freq[50], n, i, j, count;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // initially mark as unvisited
    }

    for (i = 0; i < n; i++) {
        count = 1;
        if (freq[i] == -1) {
            for (j = i+1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; // mark visited
                }
            }
            freq[i] = count;
        }
    }

    printf("Frequency of numbers:\n");
    for (i = 0; i < n; i++) {
        if (freq[i] != 0)
            printf("%d occurs %d times\n", arr[i], freq[i]);
    }
    return 0;
}
