#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "angleSolver.h"

#define RESULTMAX 110

// Get 3 side lengths, put them into the cosine formula, check if lengths are valid for calculation

// C = Cos-1((a^2 + b^2 - c^2) / 2ab)

char* analyzeAngles(int a, int b, int c)
{
	float angleA, angleB, angleC;
	char result[RESULTMAX]; 

	if (checkLengths(a, b, c) == true)
	{
		angleA = findAngle(a, b, c);
		angleB = findAngle(b, a, c);
		angleC = findAngle(c, a, b);

		snprintf(result, sizeof(result), "Angle A is %f degrees\nAngle B is %f degrees\nAngle C is %f degrees", angleA, angleB, angleC);
		printf("%s\n", result);
	}
	else
	{
		strcpy(result, "Unable to return inside angles as the dimensions you have entered do not form a regular closed triangle");
		printf("%s\n", result); 
	}

	return result; 
}

float findAngle(int a, int b, int c)
{
	float result;
	float mathTemp;

	mathTemp = c * b * 2;
	result = (c * c + b * b - a * a);
	result = (result / mathTemp);
	result = acos(result);
	result *= 180 / M_PI; 

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