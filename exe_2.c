#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable: 4996)

char userString[100] = "";
char* leftString = "";
char* rightString = "";
int onceTime = 0;

//Q1
//Split the string into two equal parts
void addString() {

	printf("enter a string up to 100 characters\n");
	gets(userString);
	int lenUserString = strlen(userString);
	int lenMiddleString = lenUserString / 2;
	leftString = (char*)malloc(50);
	strncpy(leftString, userString, lenMiddleString);
	leftString[lenMiddleString] = NULL;
	printf("%s\n", leftString);
	rightString = userString;
	rightString = rightString + lenMiddleString;
	printf("%s\n\n", rightString);
}


//Q2
//Get a string, Each time divides the length of the string in half
//Prints the left side of the string each time.
void addStringTillTheEnd() {

	if (strlen(leftString) == 1) return;
	if (onceTime == 0) {
		//Getting a string from the user
		printf("enter a string up to 100 characters\n");
		gets(userString);
		leftString = userString;
		int lenUserMiddleString = strlen(userString);
		int lenMiddleString = lenUserMiddleString / 2;
		strncpy(leftString, userString, lenMiddleString);
		leftString[lenMiddleString] = NULL;
	}
	else {
		//The rest of the times it divides in half the left side of the new string and prints the left side
		int lenUserMiddleString = strlen(leftString);
		int lenMiddleString = lenUserMiddleString / 2;
		strncpy(leftString, leftString, lenMiddleString);
		leftString[lenMiddleString] = NULL;
	}
	onceTime++;
	printf("%s\n", leftString);
	addStringTillTheEnd();
}




//Q3
//Gets a number and prints the numbers after it up to 100
void oneToAHundred(int number) {

	if (number == 101) return;
	printf("%d\n", number);
	++number;

	oneToAHundred(number);

}

//Q4
//Creates a linked list from data downloaded from a file
typedef struct _lottoItems {

	int LotteryNumber;
	char year[20];
	struct _lottoItems* next;
	struct _lottoItems* prev;

}lottoItems;

lottoItems* lottoItemsHead;
lottoItems* lottoItemsTail;

void addNewItemLotto(int LotteryNumber, char* Year);
void printlottoNumber();

//load data from the file
void readsLottoLines() {

	FILE* f = fopen("Lotto.txt", "rb");
	if (!f) exit(1); //error

	char lineInTheFile[1000] = "";

	//The titles of the data in file.
	//so that they don't enter the variables in the loop
	fgets(lineInTheFile, 1000, f);

	//Reads each line and enters the necessary data in to the variables;
	//Sends the data to a linked list.
	while ((fgets(lineInTheFile, 1000, f))) {

		int LotteryNumber =atoi( strtok(lineInTheFile, ","));
		char* Year = strtok(NULL, ",");
		addNewItemLotto(LotteryNumber, Year);
	}


	fclose(f);
	printlottoNumber();

}


//get the data and puts it in a linked list
void addNewItemLotto(int LotteryNumber, char* Year) {

	lottoItems* newItem = (lottoItems*)malloc(sizeof(lottoItems));
	if (!newItem) return 1; //error

	newItem->next = NULL;
	newItem->LotteryNumber = LotteryNumber;
	strcpy(newItem->year, Year);


	if (lottoItemsHead == NULL) {
		lottoItemsHead = newItem;
		lottoItemsTail = newItem;
		newItem->prev = NULL;
	}
	else {
		lottoItemsTail->next = newItem;
		newItem->prev = lottoItemsTail;
		lottoItemsTail = newItem;
	}


}

//Prints all the lottery numbers.
void printlottoNumber(){

	lottoItems* print = lottoItemsHead;

	while (print != NULL) {

		printf("%d\n", print->LotteryNumber);
		print = print->next;
	}
	printf("\n\n");
}


//Frees all memory allocation from the linked list.
void freeItem() {
	lottoItems* freeI = lottoItemsHead;
	lottoItems* oldFreeI = NULL;
	while (freeI) {
		oldFreeI = freeI;
		freeI = freeI->next;
		free(oldFreeI);
	}

}

//Get the lottery number, prints the year of the lottery.
void FindDateOfLottery() {

	int userLotteryNumCheck = 0;
	printf("\n\n");
	printf("please Enter lottery number -> ");
	scanf("%d", &userLotteryNumCheck);
	lottoItems* cuurntItemLotto = lottoItemsHead;

	while (cuurntItemLotto != NULL) {

		if (cuurntItemLotto->LotteryNumber == userLotteryNumCheck) {
			printf("%s\n", cuurntItemLotto->year);
			return;
		}

		cuurntItemLotto = cuurntItemLotto->next;
	}


	printf("This lottery number does not exist\n");
}


//Search data and reset the linked list
void switchCase() {

	char userResponse = "";
	while (userResponse != 'Q')
	{
		printf("\n\n");
		printf("Please choose a letter:\nN  -  Date of lottery\nQ  -  Quit\n\n");
		userResponse = getch();
		switch (userResponse) {
		case 'N':
			//Get the lottery number, prints the year of the lottery.
			FindDateOfLottery();
			break;
		
		case 'Q':
			//Exits the program and frees the memory
			freeItem();
			break;
		}
		
	}



}



int main() {

	lottoItemsHead = NULL;
	lottoItemsTail = NULL;

	//Q1
	addString();
	
	//Q2
	addStringTillTheEnd();
	
	//Q3
	oneToAHundred(1);

	//Q4
	readsLottoLines();
	switchCase();

	return 0;
}