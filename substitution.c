#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int check(string a);
int check2(string a);
string cipher(string a, string key);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int ck = check(argv[1]);
    if (ck == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        int len = strlen(argv[1]);
        if (len != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1 ;

        }

    }
   int duplicate = check2(argv[1]);
   if (duplicate == 1)
    {
       printf("Key must contain 26 characters.\n");
       return 1;
    }
    //all errors accounted for.
    string plntxt = get_string("plaintext: ");
    string ciphertxt = cipher(plntxt,argv[1]);
    printf("ciphertext: %s\n", ciphertxt);
    return 0;


}
//to check if string is all alphabets
int check(string a)
{
    int counter = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        a[i] = tolower(a[i]);
        if (a[i]>='a'&& a[i]<='z')
        continue;
        else
        counter++;
    }
    if (counter>0)
    return 1;
    else
    return 0;
}
//checking for duplicate characters
int check2 (string a)
{   int counter = 0;
    for(int i = 0; i < strlen(a); i++)
    {
        for(int j = i+1; j < strlen(a); j++)
        {
            if (tolower(a[i])== tolower(a[j]))
            counter++;
        }
    }
    if (counter>0)
    return 1;
    else
    return 0;
}
//conversion to ciphertext
string cipher (string a, string key)
{
    int c = 0;
    for (int i = 0; i < strlen(a); i++)
    {
       if (isalpha(a[i])!=0)
       {
           if(isupper(a[i]) != 0)
           {
             for (int j = 65; j <= a[i]; j++)
             {
               if (j == a[i])
              {
                  a[i] = toupper(key[c]);
                  break;

              }
                  c++;
              }
              c = 0;
           }
           else
           {
               a[i] = toupper(a[i]);
                for (int j = 65; j <= a[i]; j++)
             {
               if (j == a[i])
              {
                  a[i] = tolower(key[c]);
                  c=0;
                  break;

              }
                  c++;
             }

           }
       }
       else
       continue;
    }
    return a;
}

