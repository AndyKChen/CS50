#include <cs50.h>
#include <stdio.h>
#include <string.h>

float get_letters();
float get_words();
float get_sentences();

int main(void)
{
    string sentence = get_string("Text: ");
    int n = strlen(sentence);
    float w = 100 / get_words(sentence, n);
    float l = get_letters(sentence, n) * w;
    float s = get_sentences(sentence, n) * w;
    int index = (0.0588 * l - 0.296 * s - 15.8) + 0.5;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

float get_letters(string sentence, int length)
{
    float letters = 0;
    for (int i = 0; i < length; i++)
    {
        if ((sentence[i] > 64 && sentence [i] < 91) || (sentence[i] > 96 && sentence[i] < 123))
        {
            letters++;
        }
    }
    return letters;
}

float get_words(string sentence, int length)
{
    int words = 1;
    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

float get_sentences(string sentence, int length)
{
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
