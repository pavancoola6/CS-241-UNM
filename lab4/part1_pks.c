/*
Pavan Kumar Singara
CS241-part1
06/26/2020
*/
#include <stdio.h>
#include "lab4_pks.h"
void switch_points(float *a, float *b,float *c); /* switch points function declaration*/

int main(){

float a=1;   /* intialized all the float to some values ranging from 1 to 6*/
float b=2;
float c=3;
float x=4;
float y=5;
float z=6;


printf( "First point before -> (%f,%f)\n",a,x);   /*printing the original values of respective float variables*/
printf( "Second point before -> (%f,%f)\n",b,y);  
printf( "Third point before -> (%f,%f)\n\n",c,z);  


switch_points(&a,&b,&c); /*passing the adresses of a,b and c*/
switch_points(&x,&y,&z);
printf("First point after -> (%f, %f)\n",a,x);/*printing the switched points values of respective variables*/

printf("Second point after -> (%f, %f)\n",b,y);

printf("Third point after -> (%f, %f)\n",c,z);


return 0;
}




