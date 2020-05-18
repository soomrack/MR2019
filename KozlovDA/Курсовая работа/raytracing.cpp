#include "raytracing.h"
#define INFINITY 1000000

Polygon::Polygon(Point* array_of_vertexes, int size)
{
	polygon = array_of_vertexes;
	number_of_vertexes = size;
}

Polygon::~Polygon()
{
	delete[] polygon;
}

Polygon::Polygon(int number_of_vertexes)
{
	this->number_of_vertexes = number_of_vertexes;
	Point* new_polygon = new Point[number_of_vertexes];
	for (int i = 1; i < number_of_vertexes; i++)
	{
		new_polygon[i].x = i;
		new_polygon[i].y = i;
	}
	polygon = new_polygon;
}

bool Polygon::intersect(Point a, Point b, Point c, Point d)
{
	return (((rotate(a, b, c) * rotate(a, b, d)) < 0)  && ((rotate(c, d, a) * rotate(c, d, b)) < 0));
}

int Polygon::rotate(Point a, Point b, Point c)
{
	int z_ab_bc = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
	if (z_ab_bc > 0) return 1;
	if (z_ab_bc < 0) return -1;
	return 0;
}

bool Polygon::is_point_inside_polygon(Point point)
{
	int number_of_intersections = 0;
	Point inf;
	inf.x = INFINITY;
	inf.y = point.y;
	for (int vertex_1 = 0, vertex_2 = 1; vertex_1 < number_of_vertexes; vertex_1++, vertex_2++)
	{
		if (vertex_1 == number_of_vertexes - 1) vertex_2 = 0;
		if (intersect(polygon[vertex_1], polygon[vertex_2], point, inf))
			number_of_intersections++;
	}  
	if (number_of_intersections == 1) return true;
	else return false;
}
