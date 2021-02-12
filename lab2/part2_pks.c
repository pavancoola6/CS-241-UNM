/*
Pavan Kumar Singara
06/12/2020
CS241lab2 -part2 
*/

#include <stdio.h>
#define MAXLINE 100

int mygetline(char line[], int maxline);
void reverse(char line[]);

int main()
{
        char line[MAXLINE];
        int stringlength;
  
	while ((stringlength = mygetline(line,MAXLINE)) > 0)
		if(stringlength>50) {
	          printf ( "The line has greater than 50 characters!\n");
	          reverse(line);
		  printf("%s\n\n",line);
		  }
		  else{
		  printf("The line has 50 characters or less!\n\n");
         } 
         
         return 0;
           }
                      
/*read the input line and stores the value*/
int mygetline(char line[], int maxline){
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

/* reverse the sring */

void reverse (char s[]){
         int i, j;
         char val;
         for(j=0; s[j] !='\0';++j);
         --j;
         if(s[j]=='\n'){
         s[j]='\0';
         --j;
         }
         for (i=0;i<j;i++) {
         val=s[i];
         s[i]=s[j];
         s[j]=val;
         --j;
         }
}

