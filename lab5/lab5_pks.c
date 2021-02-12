/*pavan kumar singara
CS241- lab5
07-03-2020*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define TOTAL 196 // This number refers to the total number of countries in the csv file
#define LINE_SIZE 1024 // Max line size variable

// Here is the struct that you will need to use
struct cc {
	char country[100];
	char capital[100];
	float cap_lat;
	float cap_long;
	char code[3]; // Make code at least 3 characters long to avoid weird bug
	char continent[50];
};

void northern_most_capital(struct cc data[TOTAL]) {
float MAX_RANGE = 70.0;       // maximum and minimum ranges have been given to identify the  farthest northern most capital from csv file .
float MIN_RANGE = 64.0;
char NM_capital[100];
float NM_cap_lat;
for (int i = 0; i<TOTAL; i++) {  // here all the loops starts to check the lattitude values and print the required capital according to the ranges i provided. 
if (MIN_RANGE < data[i].cap_lat  && data[i].cap_lat < MAX_RANGE) { 
strcpy(NM_capital, data[i].capital);    // it copies the latitude value from source to destinaton NM_capital! 
NM_cap_lat = data[i].cap_lat;
}
} 
printf("the northen most capital is %s \n",NM_capital);   // after the loop stops and finds the perfect capital it then prints the northern most capital !
}
	//TODO -> Print out the capital that is the furtherst north based on latitude
// end nothern_most_capital

void southern_most_capital(struct cc data[TOTAL]) {
float MAX_LEAST_RANGE = -70.0;  //maximum and minimum least values are been given to find out the southern most capital from csv file!
float MIN_LEAST_RANGE = -40.0;
char SM_capital[100];
float SM_cap_lat;
for (int i = 0; i <TOTAL; i++) {  // all the loops starts here to check which capital has the least latitude value and prints it !
if (MAX_LEAST_RANGE < data[i].cap_lat && data[i].cap_lat < MIN_LEAST_RANGE) { 
strcpy(SM_capital, data[i].capital); // it copies the least latitude value from data[i].capital and stores in SM_capital !
SM_cap_lat = data[i].cap_lat;
printf("the southern most capital is %s \n",SM_cap_lat); // prints the southern most capital !
}

	//TODO -> Print out the capital that is the furthest south based on latitude
}
}// end southern_most_capital

void closest_to_zero_long(struct cc data[TOTAL]) {
float MAX_ABS_RANGE = 0.1;   // here im giving the float values to find out the capital which is closest to 0 from csv file!
float MIN_RANGE = 0.0;
printf("the capital that is closest to the zero longitude line is -> \n"); // here it prints the closest capital to the zero line statement! 
char capital[100];
float cap_long;
for (int i = 0; i < TOTAL; i++) {  // here the main loop starts to find out which capital has the least or zero latitude value capital!
cap_long = fabs(data[i].cap_long);  //here we used fabs function so that the closest value will be converted to positive and compare and check the least value.
if (MIN_RANGE < cap_long && cap_long < MAX_ABS_RANGE) {
strcpy(capital, data[i].capital); // the values then are shifted from data[i].capital to capital !
cap_long = data[i].cap_long;
printf("%s \n",data[i].capital, cap_long); // prints the closest zero latitude capital!
}
}
}

	//TODO -> Print out the capital which lies closest to the 0 line of longitude, for this one, you will want to make use of the fabs() function, to find the absolute value of a float
 // end closest_to_zero_long


void begins_with_k(struct cc data[TOTAL]) {
int i=0;
printf("these are the that have capitals that beigns with k are  \n"); // prints the statement!
char capital[100];
char country[100];
for (int i = 0; i < TOTAL; i++) { // all the loop starts to check which capitals have their city names starting with capital K !
if (data[i].capital[0] == 'K') {
strcpy(capital, data[i].capital); // now its been stored and shifted to capital!
printf( "%s \n",data[i].country); // prints all the countries which has their capital city starting with capital K!
} 
}
	//TODO -> this function will print out every country which has a capital that begins with the letter K.
} // end begins_with_k

void shared_name(struct cc data[TOTAL]) {
char *this_token;  //initialzed the token
printf("the countries below have capitals which share their country name: \n"); // prints the statement!
char var[50];
for (int i = 0; i < TOTAL; i++) { // here the loops start to check the countries having country name of each country and compare both and print them!
strcpy(var , data[i].capital); // stores the value from the source!
this_token = strtok(var," ");
if (strcmp(data[i].country, this_token) == 0) {
printf("%s -> %s \n ", data[i].country, data[i].capital); //prints the countries having country name of each country !
}
}
} // end sharedname

	//TODO -> Print out every country and capital pair where the country name appears in both the country name and the capital name (for instance, Mexico and Mexico City).
	//HINT 1 -> for this you will want to make use of the strcmp() function, which takes 2 strings and returns a zero if they are the same
	//HINT 2 -> Try tokenizing the capitals via a space delimiter (" ") to extract each word in the capital, this will also work if the capital is only one word long and doesn't need to be delimited

 


void main() {

	struct cc array[TOTAL];
	
	char *this_token; // Use this in conjunction with the strtok() function

	FILE *f;
	f = fopen("country-capitals.csv", "r");

	if (f == NULL) {
		printf("Try again \n");
		return;
	}

	char my_string[LINE_SIZE];
	int token_counter; // count for token
	int position = 0; //array position

	while(fgets(my_string, LINE_SIZE, f) != NULL) {
		token_counter = 0;

		this_token = strtok(my_string, ",");

		while (this_token != NULL) {
	
			if (token_counter == 0) {
				strcpy(array[position].country, this_token);
			} else if (token_counter == 1) {
				strcpy(array[position].capital, this_token);
			} else if (token_counter == 2) {
				array[position].cap_lat = (float) atof(this_token);
			} else if (token_counter == 3) {
				array[position].cap_long = (float) atof(this_token);
			} else if (token_counter == 4) {
				strcpy(array[position].code, this_token);
			} else {
				strcpy(array[position].continent, this_token);
			}


			token_counter = token_counter + 1;
			//printf("The token is -> %s \n", this_token);
			this_token = strtok(NULL, ",");
		}
		position = position + 1;


		//TODO - create function calls to the 5 above functions
		
	}

	northern_most_capital(array);   // here i am calling the above 5 five functions!
	southern_most_capital(array);
	closest_to_zero_long(array);
	begins_with_k(array);
	shared_name(array);
}
