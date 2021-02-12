/*
Pavan kumara Singara 
06/12/2020
CS241 lab2 - part 1
*/
#include<stdio.h>
#define MAXLINE 500 

int mygetline(char line[], int maxline);
int main()
         {
          int stringlength;
          char line[MAXLINE];
          int vowels;
 
          while ((stringlength = mygetline (line, MAXLINE)) > 0)
		if(line[stringlength-1]!='\n') {
	          printf ( " total number of characters : %d\n",stringlength);
		  vowels=0;
			
	          for(int i=0; i<=stringlength;i++){
		  if(line[i]=='a' || line[i]=='e' || line[i]=='i' ||line[i]=='o' ||line[i]=='u' ||
                  line[i]=='A' || line[i]=='E' || line[i]=='I' ||line[i]=='O' ||line[i]=='U')
	          ++vowels;
         }
         printf("Number of vowels: %d\n", vowels);
         } 
         return 0;
         }                 
/*read the input line and stores the value*/
int mygetline(char line[], int maxline)
{
int i=0;
int c;
maxline = maxline-1;
 while(( c= getchar()) !=EOF)
         {
          if (c== '\n')
                  break;
          if (i < maxline)
                  {
                   line[i] = c;
                   i = i+1;
                   }
          }
if (c== EOF && i == 0)
        return EOF;
line [i]= '\0';
return i;
}

