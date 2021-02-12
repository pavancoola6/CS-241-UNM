#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The below code is modified from the string compare function from the wonderful textbook
// "C in a Nutshell" written by Peter Prinz and Tony Crawford, the parameters need to be declared
// as void so that quicksort can use any kind of data
int numcmp(const void *x, const void *y) {
    
	int num1 = *(int*)x;
	int num2 = *(int*)y;

	return (num1 - num2); // This compares the 2 numbers and will return a negative, positive or zero
						  // will return negative if first number is less, zero if same and positive if num2 is less
}

void main() {

	clock_t start, end;
    double total;
	int num_of_array_ele[8] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	int *dynam_array;
	srand(0);

	for (int k = 0; k < (sizeof(num_of_array_ele) / sizeof(num_of_array_ele[0])); k++) {
               dynam_array = (int*)malloc(num_of_array_ele[k]* sizeof(int)); //used malloc to dynamically to allocate the memory!
		//TODO -> dynamically allocate space for dynam_array here


		// This will check to see if space was properly allocated, if not, return and print useful info to screen
		if (dynam_array == NULL) {

			printf("No space available\n");
			return;
		}
		
		//fill with random elements
		for (int y = 0; y < num_of_array_ele[k]; y++) {
			dynam_array[y] = rand();
		}

		start = clock();
		qsort(dynam_array, num_of_array_ele[k], sizeof(int), numcmp);
		end = clock();

		total = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The total time to execute for array of size %d -> %f \n",num_of_array_ele[k], total);

		free(dynam_array); //free this space for next iteration
	
	}
	
}
