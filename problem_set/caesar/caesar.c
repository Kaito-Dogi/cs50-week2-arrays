#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check the number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // check if each char is digit
    for (int i = 0, i_max = strlen(argv[1]); i < i_max; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // get key
    int key = atoi(argv[1]);

    // get plaintext
    string plaintext = get_string("plaintext: ");

    // encrypt plaintext
    for (int i = 0, i_max = strlen(plaintext); i < i_max; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
    }

    printf("ciphertext: %s\n", plaintext);
}