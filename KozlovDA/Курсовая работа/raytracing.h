#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <iostream>

struct Point
{
	int x;
	int y;
};

class Polygon
{
public:
	Point* polygon;
	int number_of_vertexes;
public:
	Polygon(Point* array_of_vertexes, int size);
	Polygon(int number_of_vertexes);
	~Polygon();
	bool is_point_inside_polygon(Point point);
private:
	int rotate(Point a, Point b, Point c);
	bool intersect(Point a, Point b, Point c, Point d);
};

#endif 

