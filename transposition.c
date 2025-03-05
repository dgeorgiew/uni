#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

// nomerirane na kolonite spored azbuchen red
void calculateColumnOrder(char keyword[], int order[])
{
    int len = strlen(keyword);
    for (int i = 0; i < len; i++)
    {
        order[i] = 1;
        for (int j = 0; j < len; j++)
        {
            if (keyword[j] < keyword[i])
            {
                order[i]++;
            }
        }
    }
}

// kriptirane na teksta
void encryptText(char plaintext[], char keyword[])
{
    int textLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    int order[MAX];

    calculateColumnOrder(keyword, order);

    for (int i = 0; i < textLen; i++)
    {
        char ch = plaintext[i];
        int shift = order[i % keyLen];

        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
        else if (isdigit(ch))
        {
            ch = (ch - '0' + shift) % 10 + '0';
        }
        putchar(ch);
    }
    printf("\n");
}

int main()
{
    char plaintext[MAX], keyword[MAX];

    printf("Enter plaintext: ");
    fgets(plaintext, MAX, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter keyword: ");
    fgets(keyword, MAX, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("Encrypted Text: ");
    encryptText(plaintext, keyword);

    return 0;
}
