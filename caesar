#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Making sure for only one command-line argument.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // To check if every character in argv[1] is a digit.
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Conversion of argv[1] into an 'int' from a 'string'.
    int key = atoi(argv[1]);

    // plaintext as input
    string text = get_string("Plaintext:  ");

    // For each character in input(plaintext).
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                text[i] = (text[i] - 'A' + key) % 26 + 'A';
            }
            if (islower(text[i]))
            {
                text[i] = (text[i] - 'a' + key) % 26 + 'a';
            }
        }
    }

    // ciphertext
    printf("Ciphertext: %s\n", text);
}
