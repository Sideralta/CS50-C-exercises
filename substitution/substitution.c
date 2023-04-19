#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


string incripting(string text, string code);


int main(int argc, string argv[])
{
//Check if input has two arguments
    if (argc != 2)
    {
        return 1;
    }

    int len = strlen(argv[1]);
//check if string len is 26
    if (len != 26)
    {

        return 1;
    }
    char c;
//check if is a invalid char in key
    for (int i = 0; i < 26; i++)
    {
        c = argv[1][i];
        if (!isalpha(c))
        {
            return 1;
        }


    }
    int sum;
    //transform code to uppercase
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        argv[1][i] = toupper(argv[1][i]);
        sum = 0;
    }

    // check that isnt duplicate key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                return 1;
            }
        }

    }





    string plainText = get_string("plaintext: ");
    string dtext = incripting(plainText, argv[1]);
    printf("ciphertext: %s\n", dtext);



}


string incripting(string text, string code)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp;
    char lowera;
    char lowerc;
    for (int i = 0; i < strlen(text); i++)
    {
        for (int l = 0; l < 26; l++)
        {
            if (islower(text[i]))
            {
                lowera = tolower(alpha[l]);
                lowerc = tolower(code[l]);
                if (text[i] == lowera)
                {
                    if (lowera != lowerc)
                    {
                        if (lowerc > lowera)
                        {
                            temp = lowerc - lowera;
                            text[i] += temp;
                            break;
                        }
                        else
                        {
                            temp = lowera - lowerc;
                            text[i] -= temp;
                            break;
                        }

                    }

                }


            }
            else if (text[i] == alpha[l])
            {
                if (alpha[l] != code[l])
                {
                    if (code[l] > alpha[l])
                    {
                        temp = code[l] - alpha [l];
                        text[i] += temp;
                        break;
                    }
                    else
                    {
                        temp = alpha[l] - code[l];
                        text[i] -= temp;
                        break;
                    }



                }
            }
        }
    }
    return text;
}





/* char temp;
    char p;
    char t;
    char texC;
    for (int i = 0; i < 26; i++)
    {
      temp = code[i];
      p = alpha[i];
      if ( temp != p)
      {
          t = temp - p;
      }
      texC = text[i];
      for (int l = 0; l > strlen(text) ; l++)
      {
           if (text[i] == p)
      {
          if (text[i] > temp)
          {
              text[i] -= t;
          }
          else if (text[i] < temp)
          {
              text[i] += t;
          }

      }

      }


    }
    return text; */