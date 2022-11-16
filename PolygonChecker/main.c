#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {

	int shapeChoice;

	do
	{
		printf_s("1. Triangle\n");
		printf_s("0. Exit\n");
		printf_s("Enter number: ");
		scanf_s("%1o", &shapeChoice);
		if (shapeChoice == 0 || shapeChoice == 1)	// return 'shapeChoice' when shapeChoice is 1 or 0
			return shapeChoice;						// and leave the loop

		else			//else display error msg and get input agian.
		{
			puts("You may not enter a number\nPlease enter a number next time.\n");
			rewind(stdin);		// reset the input buffer 
		}
	} while (true);

}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle\n");
	for (int i = 0; i < 3; i++)
	{
		do
		{
			// display the side that a user enters
			if (i == 0)
				printf("First side: ");
			else if (i == 1)
				printf("Second side: ");
			else
				printf("Third side: ");

			if (scanf_s("%d", &triangleSides[i]) != true)		// if a user enters something that is not a number,
			{													// display error msg and clear the buffer for the next input. 
				puts("Invalid input. Please try again.");		// 
				rewind(stdin);
			}
			else
				break;											// if the user enters valid input break the loop (Note. I don't want to use 'break', please give me some ideas)
		} while (true);
	}
	return triangleSides;										// return the triangle array that the user entered
}