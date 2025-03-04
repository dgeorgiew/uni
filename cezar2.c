#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000

char* caesar_cipher(char* str, int key) 
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));

    for(int i = 0; i < length; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') 
        { //malka bukva
            cipher[i] = ((str[i] - 'a' + key) % 26 + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') 
        { //glavna bukva
            cipher[i] = ((str[i] - 'A' + key) % 26 + 26) % 26 + 'A';
        }
        else if(str[i] >= '0' && str[i] <= '9') 
        { //cifra
            cipher[i] = ((str[i] - '0' + key) % 10 + 10) % 10 + '0';
        }
        else 
        {
            cipher[i] = str[i]; //nqma promqna
        }
    }

    cipher[length] = '\0';//raztoqnie
    return cipher;
}

void bruteforce(char* str) 
{
    printf("\nBruteforce results:\n");
    for (int key = 1; key < 26; key++) 
    { //probva 1=25
        char* decrypted = caesar_cipher(str, -key); //dekriptirane s -key
        printf("Key %2d: %s\n", key, decrypted);
        free(decrypted);
    }
}


int main() {
    char str[MAXN];
    int key, choice;

    printf("1 - Encrypt\n2 - Decrypt\n3 - Bruteforce\nChoose an option: ");
    scanf("%d", &choice);
    printf("Enter the text: ");
    scanf("%s", str);
    printf("Enter key: ");
    scanf("%d", &key);

    if(choice == 2) 
    {
        key = -key; //dekriptirane
    }

    char* result = caesar_cipher(str, key);
    printf("Result: %s\n", result);

    FILE* file = fopen("cipher.txt", "w");
    if(file) 
    {
        fprintf(file, "%s", result);
        fclose(file);
    } else 
    {
        printf("Error saving to file.\n");
    }

    free(result);
    
if (choice == 3) 
{
    bruteforce(str);
    return EXIT_SUCCESS;
}

}
