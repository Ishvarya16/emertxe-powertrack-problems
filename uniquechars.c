#include <stdio.h>
#include <string.h>

int hasUniqueChars(char *str) {
    // Assuming the string contains only ASCII characters (128 possible characters)
    int char_set[128] = {0}; // Initialize all elements to 0 (false)

    // Traverse the string
    for (int i = 0; str[i] != '\0'; i++) {
        int val = str[i];

        // If the character has already been encountered, return 0 (false)
        if (char_set[val] == 1) {
            return 0;
        }

        // Mark this character as seen (1 for true)
        char_set[val] = 1;
    }

    // If no duplicates found, return 1 (true)
    return 1;
}

int main() {
    char input[100]; // To store the input IP address (can handle up to 99 characters)

    // Prompt the user for an IP address
    printf("Enter an Input: ");
    fgets(input, sizeof(input), stdin); // Use fgets to read the input safely

    // Remove the newline character if it's there (from fgets)
    input[strcspn(input, "\n")] = '\0';

    // Check if the IP address has all unique characters
    if (hasUniqueChars(input)) {
        printf("The Input has all unique characters.\n");
    } else {
        printf("The Input has duplicate characters.\n");
    }

    return 0;
}

