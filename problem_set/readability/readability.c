#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // get text
    string text = get_string("Text: ");

    // the number of letters, words and sentences
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // count the number of letters, words and sentences
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // print the number of letters, words and sentences
    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);

    // variables of Coleman-Liau index
    float index;
    float L = 0;
    float S = 0;

    // calculate grade
    L = letters * 100.0 / words;
    S = sentences * 100.0 / words;
    index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // show result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
}