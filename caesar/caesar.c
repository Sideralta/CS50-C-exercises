
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


string incripting(string text, int n);

int main(int argc, string argv[])
{

    if (argc != 2 )
    {
         printf("Usage: ./caesar key\n");
         return 1;
    }




    for (int i = 0; i < strlen(argv[1]); i++)
    {
       if (argv[1][i] < 48 || argv[1][i] > 57 )
       {
           printf("Usage: ./caesar key\n");
        return 1;
       }

    }


    int k = atoi(argv[1]);

      if (k < 0)
    {
         printf("Usage: ./caesar key\n");
         return 1;
    }

    string plainText = get_string("plaintext: ");
    string dtext = incripting(plainText, k);
    printf("ciphertext: %s\n", dtext);



}


string incripting(string text, int n)
{
    char temp;
    char p;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] >= 65 && text[i] <= 90)
        {
            temp = text[i] - 64;
            p = (temp + n) % 26;

           if (p > 26)
            {
               p += 64;
            }
           else
            {
              p += 64;
            }
           text[i] = p;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            temp = text[i] - 96;
            p = (temp + n) % 26;
           if (p > 26)
           {
             p += 96;
           }
           else
           {
             p += 96;
           }
           text[i] = p;

        }

    }
    return text;
}