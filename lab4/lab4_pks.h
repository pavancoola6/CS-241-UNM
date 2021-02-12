void switch_points(float *a, float *b, float *c){  //function to switch_ points for_ call by reference
float t = *b; /*copy this value to t variable*/ 
*b=*a;/*copy the value of a to b*/
*a=*c;/*copy the value of b stored in c to a*/
*c=t; /*copy the value of a stored in t to c*/
}

