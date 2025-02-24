#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define MAXN 1000

char* cezar_cipher(char* str, int key)
{
    int length = strlen(str);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));

    for(int i = 0; i < length; i++)
    {
        if(str [i] >= 'a' && str[i] <= 'z') //malka bukva
        {
            cipher[i] = ((str[i] - 'a') + key) % 26 + 'a';
        }
        else if(str[i]>= 'A' && str[i] <= 'Z') //golqma bukva
        {
            cipher[i]=((str[i]-'A')+key)%26 + 'A';
        }
        else if(str[i]>= '0' && str[i] <= '9') //cifra
        {
            cipher[i]=((str[i]-'0')+key)%26 + '0';
        }
        else 
        {
            cipher[i] = str[i]; //symbol ?!,
        }
    }
    return cipher;
}


int main()
{
    char str[MAXN];
    scanf("%s" , str);
    int key;
    scanf("%d" , &key);
    char* cipher = cezar_cipher(str, key);
    printf("%s", cipher);

    FILE* file = fopen("cipher.txt", "w");
    fprintf(file, "%s", cipher);
    fclose(file);
    return EXIT_SUCCESS;
}