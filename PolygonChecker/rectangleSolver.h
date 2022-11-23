#pragma once
#define NUMPOINT 4  // for the 4 points of rectangle 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>



typedef struct rectanglepoints   //created a data structure for the 4 points of rectangle 
{
	double point_x;
	double point_y;
}POINTS;

void getRectanglePoints(POINTS pointarr[], int n);
double rectangleDist(POINTS p, POINTS q);
bool isRectangle(double distA, double distB, double distC, double distD, double distE, double distF);
double perimeterRectangle(double, double, double, double);
double CalculateArea(double dista, double distb);

// test 