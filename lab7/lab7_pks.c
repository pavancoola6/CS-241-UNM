
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define LINE 1024

// Modified struct to be set-up for a linked list implementation
typedef struct country_capital {
	char country[100];
	char capital[100];
	float cap_lat;
	float cap_long;
	char code[3]; // Make code at least 3 characters long to avoid weird bug
	char continent[50];
	struct country_capital *next_pointer;
} cc;


// This function will delete the appropriate countries and return head, which is a pointer to the first struct in the list
cc *delete_some(cc *head, cc *temp) {
temp=head;
cc *prev = NULL;
while (temp != NULL && (temp->cap_lat > 0 || temp->cap_long > 0)) {
		head =temp->next_pointer;
		free(temp);
		temp=head;
	}
	prev = temp;

	// Deal with the remaining links, other than head
	while (temp != NULL) {
		while (temp != NULL && temp->cap_lat < 0 && temp->cap_long <0) {
			prev = temp;
			temp = temp->next_pointer;
		}
	
		// We need to check for NULL in case the inner while loop iterated to the end of the list
		if (temp != NULL) {
			prev->next_pointer = temp->next_pointer;
			free(temp);
			temp = prev->next_pointer;
		}


	}
          return head;
          }
         
          
       
	//TODO -> create the code that will iterate through the linked list and delete every country that does not have 
	// both a negative capital latitude and negative capital longitude
	// Hint -> In addition to head and temp, I would initialize a Previous struct pointer to help keep track of where you are, see code I posted to Learn!

void main() {
	
	char *this_token;
	cc *head;
	cc *temp;
	cc *current;

	FILE *f;
	f = fopen("country-capitals.csv", "r");

	if (f == NULL) {
		printf("Try again \n");
		return;
	}

	char my_string[LINE];
	int counter = 0;
	int token_count;

	while(fgets(my_string, LINE, f) != NULL) {

		current  = (cc *) malloc(sizeof(cc));
		this_token = strtok(my_string, ",");
		token_count = 0;

		while (this_token != NULL) {
			if (token_count== 0) {
				strcpy(current->country, this_token);
			} else if (token_count == 1) {
				strcpy(current->capital, this_token);
			} else if (token_count == 2) {
				current->cap_lat = (float) atof(this_token);
			} else if (token_count == 3) {
				current->cap_long = (float) atof(this_token);
			} else if (token_count == 4) {
				strcpy(current->code, this_token);
			} else {
				strcpy(current->continent, this_token);
			}
			
			token_count = token_count + 1; 
			this_token = strtok(NULL, ",");
		}

		if (counter == 0) {
			head = current;
			temp = current;
		} else {
			temp->next_pointer = current;
			temp = current;
		}

		counter = counter + 1;
		
	} // end outer while loop

	temp->next_pointer = NULL;
	temp = head;
	printf("\n");
	
	printf("%s \n","Before deleting:");

	while(temp != NULL) {
		if (temp->next_pointer != NULL) {
			printf("%s, ", temp->country);
			temp = temp->next_pointer;

		} else {
			printf("%s", temp->country);
			temp = temp->next_pointer;
		}
	}
	printf("\n\n");
	head = delete_some(head,temp);
	printf("%s \n","After deleting:");
	temp = head;
	
	while(temp != NULL) {
		if (temp->next_pointer != NULL) {
			printf("%s, ", temp->country);
			temp = temp->next_pointer;

		} else {
			printf("%s", temp->country);
			temp = temp->next_pointer;
		}
	}
      printf("\n\n");


       

	//TODO -> Create function call here

	//TODO -> print out the updated linked list
	
} // end main
