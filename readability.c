#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//function declarations
int count_letters(string text);
int count_words(string text);
int count_sen(string text);

int main(void)
{
    //prompts for text
    string text = get_string("Text: ");

    //calls functions and variables store numbers
    int numlet = count_letters(text);
    int numword = count_words(text);
    int numsen = count_sen(text);

    //calculations for formula
    float L = (float) numlet / (float) numword * 100;
    float S = (float) numsen / (float) numword * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = round(index);

    //checking for max and min and printing
    if (rounded > 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", rounded);
    }
}

//function to add number of letters together
int count_letters(string text)
{
    int letters = 0;
    int i = 0;
    int n = strlen(text);

    for (i = 0; i < n; i++)
    {
        //checks if character is alphabetical, and if it is, adds to variable letters
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//function to count words
int count_words(string text)
{
    int words = 0;
    int j = 0;
    int n = strlen(text);

    for (j = 0; j <= n; j++)
    {
        //checks if character is a space, if it is it adds to variable words
        if ((text[j]) == ' ')
        {
            words++;
        }
    }
    return words + 1;

}

//function to count sentences
int count_sen(string text)
{
    int sen = 0;
    int z = 0;
    int n = strlen(text);

    for (z = 0; z <= n; z++)
    {
        //checks for punctuation, adds to variable sen
        if (text[z] == '.' || text[z] == '!' || text[z] == '?')
        {
            sen++;
        }
    }
    return sen;

}