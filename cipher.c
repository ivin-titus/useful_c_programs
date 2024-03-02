#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 255

void decrypt(char* word, int key);
void encrypt(char* word, int key);

// Global Variable that accepts encrypted / decrypted string
char that_text[MAX];

int main(int argc, char* argv[]) {
    int key;
    char use[MAX];

    // saves value from argument as key
    if (argc == 3) {
        key = atoi(argv[2]);
        strcpy(use, argv[1]);
    } else {
        printf("Use (Encrypt or Decrypt): ");
        fgets(use, sizeof(use), stdin);
        use[strcspn(use, "\n")] = '\0'; // Remove newline character from fgets input

        // Check if the entered method is valid
        if (strcmp(use, "Encrypt") && strcmp(use, "Decrypt")) {
            printf("Given Method Not Allowed - Allowed: Encrypt / Decrypt\n");
            return 3;
        }

        printf("Key: ");
        scanf("%d", &key);
        getchar(); // Consume newline character left in the input buffer
    }

    // returns 1 if key < 1
    if (key < 1) {
        printf("Key Must be greater than 0 \n");
        return 4;
    }

    // saves text
    char word[100]; // Adjust the size as needed
    printf("Text you Want to %s: ", use);
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // Remove newline character from fgets input

    // function calling and arguments passing
    if (!strcmp(use, "Encrypt")) {
        encrypt(word, key);
    } else {
        decrypt(word, key);
    }

    // result
    printf("%sed Text: %s\n", use, that_text);

    return 0;
}

void encrypt(char* word, int key) {
    // saves length of string
    int n = strlen(word);

    // for null terminator
    char cypher[n + 1];

    // checks char array word and saves values to array cypher
    for (int i = 0; i < n; i++) {
        if (isalpha(word[i])) {
            char base = islower(word[i]) ? 'a' : 'A';
            cypher[i] = (word[i] - base + key) % 26 + base;
        } else {
            cypher[i] = word[i];
        }
    }

    // null terminator
    cypher[n] = '\0';

    // Copies encrypted code to global variable
    strcpy(that_text, cypher);
}

void decrypt(char* word, int key) {
    // saves length of string
    int n = strlen(word);

    // for null terminator
    char cypher[n + 1];

    // checks char array word and saves values to array cypher
    for (int i = 0; i < n; i++) {
        if (isalpha(word[i])) {
            char base = islower(word[i]) ? 'a' : 'A';
            cypher[i] = (word[i] - base + 26 - key) % 26 + base;
        } else {
            cypher[i] = word[i];
        }
    }

    // null terminator
    cypher[n] = '\0';

    // copies decrypted text to global variable
    strcpy(that_text, cypher);
}
