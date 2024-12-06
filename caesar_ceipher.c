#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + shift) % 26) + 'a'; // Encrypt lowercase
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A'; // Encrypt uppercase
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain the same
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext
}

void decrypt(char *ciphertext, int shift, char *decryptedtext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            decryptedtext[i] = ((ciphertext[i] - 'a' - shift + 26) % 26) + 'a'; // Decrypt lowercase
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decryptedtext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A'; // Decrypt uppercase
        } else {
            decryptedtext[i] = ciphertext[i]; // Non-alphabetic characters remain the same
        }
        i++;
    }
    decryptedtext[i] = '\0'; // Null terminate the decrypted text
}

int main() {
    char plaintext[100], ciphertext[100], decryptedtext[100];
    int shift;

    // Input for encryption
    printf("Enter shift value: ");
    scanf("%d", &shift);
    getchar();  // to consume newline character after integer input

    // Ensure valid shift value
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! It must be between 1 and 25.\n");
        return 1;
    }

    printf("Enter the plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline from fgets

    // Encrypt the message
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}
