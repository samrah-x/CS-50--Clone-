#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error 446\n");
        return 1;
    }
    else
    {
        string input = argv[1];
        replace(input);
        printf("Modified string: %s\n", input);
        return 0;
    }
}

string replace(string str)
{
    string new = str;
    for (int i = 0, n = strlen(new); i < n; i++)
    {
        switch (new[i])
        {
            case 'a':
                new[i] = '6';
                break;

            case 'e':
                new[i] = '3';
                break;

            case 'i':
                new[i] = '1';
                break;

            case 'o':
                new[i] = '0';
                break;

            // Add cases for uppercase vowels
            case 'A':
                new[i] = '6';
                break;

            case 'E':
                new[i] = '3';
                break;

            case 'I':
                new[i] = '1';
                break;

            case 'O':
                new[i] = '0';
                break;

            default:
                break;
        }
    }
    return new;
}
