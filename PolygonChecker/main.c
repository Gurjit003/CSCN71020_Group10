#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "angleSolver.h"
#include "RectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 0:
			continueProgram = false;
			break;
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n\n", result);
			analyzeAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			int rectangleCoordinates[8] = { 0,0,0,0,0,0,0,0 };
			int* rectangleCoordinatesPtr = getRectangleCoordinates(rectangleCoordinates);
			char* resultForRectangle = analyzeRectangle(rectangleCoordinates[0], rectangleCoordinates[1], rectangleCoordinates[2], rectangleCoordinates[3], rectangleCoordinates[4], rectangleCoordinates[5], rectangleCoordinates[6], rectangleCoordinates[7]);
			printf("%s\n", resultForRectangle);
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
	printf_s("1. Triangle\n");
	printf("2. Rectangle\n");
	printf_s("0. Exit\n");
	

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

int* getRectangleCoordinates(int* RectangleCoordinates)
{
	printf_s("Enter the 8 coordinates of the rectangle.\n ");
	printf("Write x y coordinates divided by enter.\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\nx%d = ", i + 1);
		scanf_s("%d", &RectangleCoordinates[i]);
		printf("y%d = ", i + 1);
		scanf_s("%d", &RectangleCoordinates[i + 4]);
	}
}