#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validate_key();
int main(int argc, string argv[])
{
    // printf("%d", argc);
    if (argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int length = strlen(argv[1]);

    if (validate_key(argv[1]))
    {
        return 1;
    }

    else
    {
        string ptext = get_string("Plain Text: ");
        char plain[length];
        char cipher[strlen(ptext)];

        // creates corresponding plain text key of correct capitalization
        for (int i = 0; i < length; i++)
        {

            if (argv[1][i] > 64 && argv[1][i] < 91)
            {
                plain[i] = 65+i;
            }
            else
            {
                plain[i] = 97+i;
            }
        }

        // scans through plain key and original text until there is a match. When found, add corresponding letter to final cipher
        for (int j = 0; j < strlen(ptext); j++)
        {
            if ((ptext[j] > 64 && ptext[j] < 91) || (ptext[j] > 96 && ptext[j] < 123))
            {
                for (int k = 0; k < length; k++)
                {
                    if (plain[k] == ptext[j] || plain[k] == ptext[j] +32 || plain[k] == ptext[j] - 32)
                    {
                        cipher[j] = argv[1][k];
                    }
                }
            }

            // if not an alphabetical character, simply add same value to final cipher
            else
            {
                cipher[j] = ptext[j];
            }
        }

        // corrects capitlization in final cipher
        for (int x = 0; x < strlen(cipher); x++)
        {

            if (ptext[x] > 64 && ptext[x] < 91)
            {

                if (cipher[x] > 90 && cipher[x] < 123)
                {
                cipher[x] -= 32;
                }
            }
            else if ((ptext[x] > 90 && ptext[x] < 123))
            {
                if (cipher[x] > 64 && cipher[x] < 91)
                {
                cipher[x] += 32;
                }

            }
        }

        printf("ciphertext: ");

        // prints final cipher array character by character
        for (int l = 0; l < strlen(cipher); l++)
        {
            printf("%c", cipher[l]);
        }
        printf("\n");
        return 0;
    }
}

bool validate_key(string key)
{

    int length = strlen(key);

    // Check for duplicate letters
    for (int j = 0; j < length-1; j++)
    {
        for (int k = j+1; k < length; k++)
        {
            if ((int)key[j] == (int)key[k])
            {
                printf("Key must not contain repeated characters.\n");
                return true;
            }
        }
    }

    // validate alphabetical
    for (int i = 0; i < length; i++)
    {
        if ((key[i] > 90 && key[i] < 97) || key[i] > 122 || key[i] < 65)
        {
            printf("Key must only contain alphabetic characters.\n");
            return true;
        }
    }

    // validate length
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return true;
    }

    else
    {
        return false;
    }

}
