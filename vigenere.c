#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Check if the user provided 1 command-line argument
    if (argc != 2)
    {
        printf("You have to enter a keyword without space to determine how many chars to shift!\n");
        return 1;
    }

    //Loop through each character of the keyword to determine if it's consisted
    //of alphabetical characters
    int keywordlength = strlen(argv[1]);
    int shiftkey[keywordlength];
    int shiftkeycounter = 0;
    int key;

    for (int i = 0; i < keywordlength; i++)
    {
        //Check if it's alphabetical character
        if (!isalpha(argv[1][i]))
        {
            printf("Keyword must be consisted of only alphabetical characters!\n");
            return 1;
        }
    }
    string keyword = argv[1];
    printf("Keyword: %s\n", keyword);

    //Loop for accessing to each char of the keyword to store int values of ASCII chars
    for (int k = 0; k < keywordlength; k++)
    {
        //Check if it's uppercase and assign its value to shiftkey[k]
        if (isupper(keyword[k]))
        {
            shiftkey[k] = (keyword[k] - 65);
        }
        //Check if it's lowercase and assign its value to shiftkey[k]
        else
        {
            shiftkey[k] = (keyword[k] - 97);
        }
    }

    //Get plaintext
    string plaintext = get_string("Enter the plaintext to be ciphered: ");

    //Get the length of the string to loop through each char
    int plaintextlength = strlen(plaintext);

    printf("ciphertext: ");

    //Loop through each char of the plaintext
    for (int j = 0; j < plaintextlength; j++)
    {
        //Check if it's alphabetic
        if (isalpha(plaintext[j]))
        {
            //After verifying that it's an alphabetical character, means that we have to use a key
            //Mod shiftkeycounter to keywordlength so that we never exceed keywordlength
            //Assing the modded value'th element of shiftkey[] to key
            key = shiftkey[(shiftkeycounter % keywordlength)];

            //Check if j'th char of the plaintext is uppercase
            if (isupper(plaintext[j]))
            {
                int upperindex = ((plaintext[j] - 65 + key) % 26);
                int cipheredchar = upperindex + 65;
                printf("%c", cipheredchar);
            }
            else
            {
                int lowerindex = ((plaintext[j] - 97 + key) % 26);
                int cipheredchar = lowerindex + 97;
                printf("%c", cipheredchar);
            }
            shiftkeycounter++;
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
    return 0;
}
