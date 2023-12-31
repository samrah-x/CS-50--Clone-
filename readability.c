#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototype function
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate L and S as floating-point values
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = (int) round(index);

    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", rounded_index);
        return 0;
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
