#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>

#include "angleSolver.h"

// Get 3 side lengths, put them into the cosine formula, check if lengths are valid for calculation

// C = Cos-1((a^2 + b^2 - c^2) / 2ab)

void analyzeAngles(int a, int b, int c)
{
	float angleA, angleB, angleC;

	if (checkLengths(a, b, c) == true)
	{
		angleA = findAngle(a, b, c);
		angleA *= 180 / M_PI;
		printf("Angle A is %f degrees\n", angleA);

		angleB = findAngle(b, a, c);
		angleB *= 180 / M_PI;
		printf("Angle B is %f degrees\n", angleB);

		angleC = findAngle(c, a, b);
		angleC *= 180 / M_PI;
		printf("Angle C is %f degrees\n", angleC);

	}
	else
	{
		printf("unable to return inside angles as the dimensions you have enetered do not form a regular closed triangle");
	}
}

float findAngle(int a, int b, int c)
{
	float result;
	float mathTemp;

	mathTemp = c * b * 2;
	result = (c * c + b * b - a * a);
	result = (result / mathTemp);
	result = acos(result);

	return result;
}

bool checkLengths(int a, int b, int c)
{
	if (b + c > a && a + c > b && a + b > c && a > 0 && b > 0 && c > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}