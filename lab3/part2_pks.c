/*
Pavan Kumar Singara
06/19/2020
CS241 Lab3 - Part 2
*/

#include <stdio.h>

unsigned int shift(unsigned int a)   // Used shift function , which shifts the number from right to left onlt at once . 
{
return a<<1;
}

unsigned int AND(unsigned int a,unsigned int b) // used AND operator of two given unsigned numbers (a and b)
{
return a & b;
}
unsigned int XOR(unsigned int a,unsigned int b)  // used OR operator for twon given unsigned numbers (a and b)
{
return a ^ b;
}

unsigned int add(unsigned int x,unsigned int y) // This is where my iterative process starts, with the help of two numbers using only bit.
{
while (y!=0)
{
unsigned int values = x & y;
x = x ^ y;
y = shift(values);
}
printf("%d\n",x);
return x;
}

unsigned int main()   // here i initialized the values to the variables and printing the sum !
{
unsigned int a=4000,b=6000;
printf("sum of %d and %d \n",a,b);
add(a,b);
return 0;
}
