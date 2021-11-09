#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int rows = get_int("height =\n");
    if (rows <=0||rows>8)
    {

       while(rows <=0 ||rows > 8)
 if       (rows<= 0 || rows >= 8)

        rows = get_int("height = \n");

        else

        break;
    }

    int h=0;
string hash ="#";
   for(int j=1;j<=rows;j++)
   {
       for(int k=0;k<(rows-j);k++)
       {
           printf(" ");
       }
       for(int l=0;l<j;l++)
       {
           printf("%s",hash);
       }
       for(int m=0;m<2;m++)
       {
           printf("%.s %.s",hash,hash);
       }
       for(int n=0;n<j;n++)
      {
          printf("%s",hash);
      }
      printf("\n");
   }
}

