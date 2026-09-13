#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // input for User
    string text = get_string("Text: ");

    // Count number of letters, words and sentences.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index.
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Results.

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf(" Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// For Letters.
int count_letters(string text)
{
    // Intial count
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            count++;
        }
        else if (islower(text[i]))
        {
            count++;
        }
    }
    return count;
}

// For Words.
int count_words(string text)
{
    // Intial count
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

// For Sentences.
int count_sentences(string text)
{
    // Intial count.
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
