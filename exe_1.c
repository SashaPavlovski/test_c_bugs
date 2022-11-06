#include < stdio.h>
#pragma warning(disable: 4996)
//Q1

int main() {
	int a = 4, b = 7;
	float c;
	scanf("%f",&c);
	if (5 == c)
	printf("%f", c);

	return 0;
}

//Built-in libraries in windows are written between two < library >.
// This command must be in every project to work #pragma warning(disable: 4996).
//Between a and b there was a separation of (;) and to define a second number of the same type we do(,)between them.
//When using scanf to put into the variable what the user wrote, we will write before it (&).
//to make a comparison, in c you need to do the sign (=)  twice (==).
// A print function is called printf.

//Q2
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int x = 4, y = 8;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	puts("***** Section A *****");
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);
	// Section B - Print the static array "nums".
	puts("***** Section B *****");
	int i = 0;
	while (i < 6) {
		nums[i] = i;
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++;
	}

	// Section C - Print allocated array.
	puts("***** Section C *****");
	arrPtr = (int*)malloc(sizeof(int) * 6);
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			arrPtr[i] = i;
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	free(arrPtr);
	return 0;
}

	// This command must be in every project to work #pragma warning(disable: 4996).
	// in b,inside the loop you need something to advance the loop so that it is not infinite.
	//When doing malloc, this function returns void* and we need to define what type of pointer we want it to return.(type casting).
	//If you need an array of size 6 bytes, you need alloc int 6 times.
	//Parentheses of the main function were missing


////Q3


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
// struct to collect counting info about english letters found in a text file.



typedef struct _letter {
	char small;
	char big;
	int counter;
	struct _letter* next;
	struct _letter* prev;
}letter;

letter* HEAD;
letter* TAIL;

//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}



int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[27] = {0};
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");
	if (!f) {
     //error
	   return;
	}

	// Dis[lay the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF) {
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); ++i) {
			if (readChar == smallAlpha[i] || readChar == bigAlpha[i]) {

				lettersCountArr[i]++;

			}

		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	HEAD = NULL;
	TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); ++j) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			puts("Error Allocating Memory!");
			exit(1);
		}
		letterItem->small = smallAlpha [j];
		letterItem->big = bigAlpha[j];
		letterItem->counter = lettersCountArr[j];
		// Creating the linked list
		
		if (HEAD == NULL) {
			HEAD = letterItem;
			TAIL = letterItem;
			letterItem->prev = NULL;
			letterItem->next = NULL;
		}
		else
		{
			TAIL->next = letterItem;
			letterItem->prev = TAIL;
			TAIL = letterItem;
			TAIL->next = NULL;
		}
	
	}
	return 0;
}
//Windows directories are with .h
//In order for the list to be linked, you need to make two pointers, the tail and the next.
//To access a linked list you need a variable to hold the first variable of the list in the head.
//and keep the last place In TAIL.
//HEAD and TAIL should be global so you can use it anywhere
//When you open a file you should see that it is really opened.
//To use the strlen function, need the library #include <string>.
//file ends in EOF.
//The string length is 27.
//There was no parentheses in the condition
//You have to enter the letters from the array each time.
//We need a condition that will save the first letterItem so that we can access it later.