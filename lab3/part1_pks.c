/*
Pavan Kumar Singara
06/19/2020
CS241 Lab3 - Part 1

*/#include<stdio.h>
void mask(unsigned int x);
int main()
{

          unsigned int number= 8000;              // Initilaized the number to 8000.
          printf("the number %d\n",number);
          mask(number);                            // I called the Mask function !
          return 0;
          }
          void mask(unsigned int number)
          {
          unsigned int new=0;
          unsigned int val=255,i,length=4;
          int x[length];
          
         for(i=0;i<4;i++)                    // Here the And operaton loop starts
         {
         x[i]=number&val;
         val=val << 8;
         }
         for (i=0;i<4;i++)                   // Here the OR operation of x[i]and 'new' to compare.
         {
         new=(new | x[i]);
         }
         printf("the number after binary is %d\n",new); // here it prints the final number !
         }
        
         
        
          
          
          
