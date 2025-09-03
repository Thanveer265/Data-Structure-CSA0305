#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100];
    int i, valid = 1;
    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            valid = 0;
            break;
        }
    }

    if (valid) printf("Valid String (only alphabets)\n");
    else printf("Invalid String\n");

    return 0;
}
