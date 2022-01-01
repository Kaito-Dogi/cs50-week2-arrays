#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check the number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check if the argument length is valid
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check if the argument is a valid string
    // prepare an array to count the number of each char
    int char_nums[26];
    for (int i = 0; i < 26; i++)
    {
        char_nums[i] = 0;
    }

    // count each char
    for (int i = 0; i < 26; i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            char_nums[argv[1][i] - 'a']++;
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            char_nums[argv[1][i] - 'A']++;
        }
    }

    // check the number of chars
    for (int i = 0; i < 26; i++)
    {
        if (char_nums[i] != 1)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    // get plaintext
    string plaintext = get_string("plaintext:  ");

    // encrypt plaintext
    for (int i = 0, i_max = strlen(plaintext); i < i_max; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] = tolower(argv[1][plaintext[i] - 'a']);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = toupper(argv[1][plaintext[i] - 'A']);
        }
    }

    // print ciphertext
    printf("ciphertext: %s\n", plaintext);
}