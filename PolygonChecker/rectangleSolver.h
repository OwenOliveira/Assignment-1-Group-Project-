#pragma once
#define NUMPOINT 4  // for the 4 points of rectangle 




struct rectanglepoints   //created a data structure for the 4 points of rectangle 
{
	double point_x;
	double point_y;
};

void getRectanglePoints(struct rectanglepoints pointarr[], int n);
double rectangleDist(struct rectanglepoints p, struct rectanglepoints q);
void isRectangle(struct rectanglepoints pointarr[]);
double perimeterRectangle(double, double, double, double);
double CalculateArea(double dista, double distb);

// test 