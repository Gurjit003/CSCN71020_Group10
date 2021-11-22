#include <stdio.h>
#include "RectangleSolver.h"

char* analyzeRectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	char* conclusion = "";
	int* area = NULL;
	int* perimeter = NULL;
	if ((x1 == x2) && (y1 != y2) && (y1 == y4) && (y1 != y3) && (y2 == y3) && (x3 == x4) && (x1 != x4) && (x1 != x3) && (x2 != x3) && (x2 != x4))
	{
		conclusion = "it forms a rectangle.\n";
		if ((y2 - y1 == x4 - x1) && (y2 - y1 == y3 - y4) && (y2 - y1 == x3 - x2))
		{
			conclusion = "your rectangle is a square. Try again!\n";
		}
		else
		{
			perimeter = (y2 - y1) + (x3 - x2) + (y3 - y4) + (x4 - x1);
			area = (y2 - y1) * (x3 - x2);
		}
	}
	else
	{
		conclusion = "4 points do not form a rectangle. Try again!\n";
	}
	printf(" Perimeter is equal: %d\n", perimeter);
	printf(" Area is equal: %d\n", area);
	return conclusion;
}