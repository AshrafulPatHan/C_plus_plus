 
#include <stdio.h>

int main() {
    char text[100];

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    printf("You entered: %s", text);

    return 0;
}
