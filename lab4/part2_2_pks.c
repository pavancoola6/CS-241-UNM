/*
pavan Kumar Singara
CS241-part2_2
06/26/2020
*/#include <stdio.h>
#include <time.h>
#define NUMBER_OF_ROWS 100

void reverse_rows_pointer(char *pointer_arr[NUMBER_OF_ROWS]) {
	//TODO complete this function
	char *arr[100];
	int i=99;   /* intialized the i and j for the loop to start since its 1 and 100 , i took o and 99 which N-1 so the loop can be started!*/

	int j=0;
	for(j=0; j<100; j++){
 	while(i>=0){                       /*loop to reverse array*/
 	arr[j] = pointer_arr[i];
 	
 	i--;     /*decrement array pointer*/
 	j++;     /*increment array pointer*/
	}	
}
i=0;
while(i<100){                     /* printing the pointer array with while condition.*/
pointer_arr[i] = arr[i];
//printf(pointer_arr[i]);
i++;
}
}




void main() {

	clock_t start, end;
    double total;
	char *string_pointers[NUMBER_OF_ROWS] = {"This is line -> 1",
									"This is line -> 2",
									"This is line -> 3",
									"This is line -> 4",
									"This is line -> 5",
									"This is line -> 6",
									"This is line -> 7",
									"This is line -> 8",
									"This is line -> 9",
									"This is line -> 10",
									"This is line -> 11",
									"This is line -> 12",
									"This is line -> 13",
									"This is line -> 14",
									"This is line -> 15",
									"This is line -> 16",
									"This is line -> 17",
									"This is line -> 18",
									"This is line -> 19",
									"This is line -> 20",
									"This is line -> 21",
									"This is line -> 22",
									"This is line -> 23",
									"This is line -> 24",
									"This is line -> 25",
									"This is line -> 26",
									"This is line -> 27",
									"This is line -> 28",
									"This is line -> 29",
									"This is line -> 30",
									"This is line -> 31",
									"This is line -> 32",
									"This is line -> 33",
									"This is line -> 34",
									"This is line -> 35",
									"This is line -> 36",
									"This is line -> 37",
									"This is line -> 38",
									"This is line -> 39",
									"This is line -> 40",
									"This is line -> 41",
									"This is line -> 42",
									"This is line -> 43",
									"This is line -> 44",
									"This is line -> 45",
									"This is line -> 46",
									"This is line -> 47",
									"This is line -> 48",
									"This is line -> 49",
									"This is line -> 50",
									"This is line -> 51",
									"This is line -> 52",
									"This is line -> 53",
									"This is line -> 54",
									"This is line -> 55",
									"This is line -> 56",
									"This is line -> 57",
									"This is line -> 58",
									"This is line -> 59",
									"This is line -> 60",
									"This is line -> 61",
									"This is line -> 62",
									"This is line -> 63",
									"This is line -> 64",
									"This is line -> 65",
									"This is line -> 66",
									"This is line -> 67",
									"This is line -> 68",
									"This is line -> 69",
									"This is line -> 70",
									"This is line -> 71",
									"This is line -> 72",
									"This is line -> 73",
									"This is line -> 74",
									"This is line -> 75",
									"This is line -> 76",
									"This is line -> 77",
									"This is line -> 78",
									"This is line -> 79",
									"This is line -> 80",
									"This is line -> 81",
									"This is line -> 82",
									"This is line -> 83",
									"This is line -> 84",
									"This is line -> 85",
									"This is line -> 86",
									"This is line -> 87",
									"This is line -> 88",
									"This is line -> 89",
									"This is line -> 90",
									"This is line -> 91",
									"This is line -> 92",
									"This is line -> 93",
									"This is line -> 94",
									"This is line -> 95",
									"This is line -> 96",
									"This is line -> 97",
									"This is line -> 98",
									"This is line -> 99",
									"This is line -> 100"};
        reverse_rows_pointer(string_pointers);
       									

	//TODO first create a function call here one time after completing the reverse_rows_pointer() function and make sure that its working correctly

	start = clock();
	int i;
	for(i=0; i<1001; i++)
	reverse_rows_pointer(string_pointers);
		
	// TODO Once you have verified that your reverse_rows_pointer() function is working properly, call it in a for loop here, where the for loop will iterate for one of the numbers listed in the lab4 pdf (ex: 1,000)
	end = clock();

	total = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The total time to execute -> %f \n", total);

}
