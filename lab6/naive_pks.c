#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void naive_bubble(int *dynamic, int iter) {
   for(int j=0;j<iter;j++)  // read all the elements of the array !!
  {
    for(int i=0;i<iter-1;i++)   // compare the elements of the array!!
    {
      if(dynamic[i]>dynamic[i+1])
      {                                         // used swapping here !
        dynamic[i]=dynamic[i]+dynamic[i+1];
        dynamic[i+1]=dynamic[i]-dynamic[i+1];
        dynamic[i]=dynamic[i]-dynamic[i+1];
      }
    }
  }
} // TODO -> create a naive bubble sorting algorithm that will sort dynamic

	
void main() {

	clock_t start, end;
    double total;
	int num_of_array_ele[8] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	int *dynam_array;
	srand(0);

	for (int k = 0; k < (sizeof(num_of_array_ele) / sizeof(num_of_array_ele[0])); k++) {
            dynam_array = (int*)malloc(num_of_array_ele[k]* sizeof(int)); //used malloc to dynamically allocate the memory!
            
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

		// This will time each sort
		start = clock();
		naive_bubble(dynam_array, num_of_array_ele[k]);
		end = clock();

		// This will calculate the total running time and print it out to the screen for user to see
		total = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The total time to execute for array of size %d -> %f \n",num_of_array_ele[k], total);

		free(dynam_array); //free this space for next iteration
	
	}
	
}
