#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check for one command line arg
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // define key
    string key = argv[1];

    // check if digit
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // must be 26 chars
    if (strlen(key) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // must not repeat alphabets
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    // get plaintext
    string plaintext = get_string("plaintext: ");

    for (int i = 0; i < strlen(key); i++)
    {
        // covert to a single case
        if (islower(key[i]))
        {
            key[i] -= 32;
        }
    }

    printf("ciphertext: ");

    // convert to cipher
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
