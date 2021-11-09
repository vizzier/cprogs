#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include <ctype.h>
#include <math.h>
int readck (int a, int b, int c);
int main (void)
{
    string excerpt = get_string("enter the excerpt\n");
    int wcounter = 1;
    int scounter = 0;
    int avsum = 0;
    int lcounter = 0;
    int length = strlen(excerpt);
    //finding the sentences in array
    for (int i = 0; i <= length;i++)
    {
        if (excerpt[i]=='!'||excerpt[i]=='?'||excerpt[i]=='.')

         scounter++;

     }
//finding the words and letters in array.
for (int i = 0;i < length;i++)
{
    if (isspace(excerpt[i])!=0)

    wcounter++;

   else if ((excerpt[i]>='a'&& excerpt[i]<='z')||(excerpt[i]>='A'&& excerpt[i]<='Z'))

    lcounter++; 

}  
  int index = readck(wcounter,scounter,lcounter);  
  if (index < 1)
  printf("Before Grade 1\n");
  else if (index>16)
  printf ("Grade 16+\n");
  else
  printf ("Grade %d\n",index);

}
int readck (int a, int b, int c)
{
    float perhuns = (b*100/(float)a);
    printf("%f\n",perhuns);
    float perhunl = (c*100/(float)a);
    printf ("%f\n",perhunl);
   float indexR = 0.0588 * perhunl - 0.296 * perhuns - 15.8;
   printf ("%f\n",indexR);
   return round(indexR);
}
