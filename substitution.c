#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int validateKey(string key);
void encryptText(string key, string text);
char encryptChar(string key, char c);

int KEYLENGTH = 26; 

int main(int argc, string argv[])
{

    // checks if only 2 arguments passed in
    if (argc != 2)
    {
        printf("Key error, no key.\n");
        return 1;
    }
    
    string key = argv[1];
    
    // checks for valid key
    if (validateKey(key))
    {
        return 1;
    }
    
    // gets input from user to encrypt
    string text = get_string("plaintext: ");
    encryptText(key, text);
    
    return 0;
}

int validateKey(string key)
{
    int keyCount = strlen(key);
    
    // checks if key is correct lenght
    if (keyCount != KEYLENGTH)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    int sumOfASCIIUppercase = 2015;
    
    char alph[26];
    
    for (int i = 0; i < KEYLENGTH; i++)
    {
        char c = key[i];
        
        // checks to see if key is only alpha
        if (!isalpha(c))
        {
            printf("Key error, nonalpha.\n");
            return 1;
        }
        
        int n = (int) toupper(c) - 65;
        
        //checks for duplicate in key
        if (alph[n] != '\0')
        {
            printf("Key error, duplicate.\n");
            return 1;
        }
        alph[n] = c;
    }
    
    return 0;

}

void encryptText(string key, string text)
{
    printf("ciphertext: ");
    
    // cycles through each character of the user input
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            c = encryptChar(key, c);
        }

        printf("%c", c);
    }
    
    printf("\n");
}

char encryptChar(string key, char c)
{
    // encrypts character using key
    if (isupper(c))
    {
        int n = (int) c - 65;
        return toupper(key[n]);
    }
    else
    {
        int n = (int) c - 97;
        return tolower(key[n]);
    }
}
