#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    long card = get_long("enter your card number:  ");
    long card2 = card;
    int counter = 0;
    int sum=0;
    int twoc, multi =0;
        while (card2>=10)
        {
            card2=(card2/10);
        counter++;
        }
        if (counter<12)
        printf("INVALID\n");
        else
        {
        long carr[counter+1];
        for(int i=0;i<=counter;i++)
        {
             carr[i]= (card%10);
            card =(card/10);
            if (card<0)
            break;
        }
        //this loop is to multiply and separate and get the sum
        for (int c2=1; c2<=counter;c2=c2+2)
        {
         multi=carr[c2]*2;
        //if multi is greater than 10, ie a two digit number
        if (multi>=10)
        {
            for (int c3=0;c3<2&&multi>0;c3++)
        {

           twoc= twoc+(multi%10);
           multi = (multi/10);
        }
          sum = sum+twoc;
          twoc=0;
          multi=0;
        }
        else (sum = sum+multi);
        }
        //now for the digits not multiplied by 2
        int sumtwo=0;
        for (int c3=0;c3<=counter;c3+=2)
        {
         sumtwo = sumtwo+carr[c3];
        }
        sumtwo= sumtwo+sum;

       if (sumtwo%10!=0)
        printf("INVALID\n");
        //now lets check what brand of card it is
        else
        {
            if (carr[counter]==4) printf("VISA\n");
           else if (carr[counter]==55)
               printf("MASTERCARD\n");
         else if (carr[counter]==3) printf("AMEX\n");
             else printf("INVALID\n");

           }
        }
}
