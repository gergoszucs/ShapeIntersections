#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include "line.h"
#include "circle.h"

#include <fstream>

using namespace Intersections;

void check_for_intersections(const Shape* line, const Shape* other, std::list<Point<double>>& intersections);

int main() {
	std::list<Shape*> shapes;
	std::list<Point<double>> intersections;
	std::ifstream infile("input.txt");

	int shapeCount, x1, y1, x2, y2, radius;
	char type;

	infile >> shapeCount;

	for (int i = 0; i < shapeCount; i++) {
		infile >> type;

		if (type == 'L') {
			infile >> x1 >> y1 >> x2 >> y2;
			Shape* line = new Line(x1, y1, x2, y2);
			std::for_each(shapes.begin(), shapes.end(), [&line, &intersections](const Shape* other) { check_for_intersections(line, other, intersections); });
			shapes.push_back(line);
		}
		else {
			infile >> x1 >> y1 >> radius;
			Shape* circle = new Circle(x1, y1, radius);
			shapes.push_back(circle);
		}
	}

	std::cout << std::fixed << std::setprecision(4);
	for(auto p : intersections) {
		std::cout << p.get_x_coord() << " " << p.get_y_coord() << std::endl;
	}

	std::cin.get();
}

void check_for_intersections(const Shape* shape, const Shape* other, std::list<Point<double>>& intersections) {
	if (shape->is_intersecting(other)) {
		intersections.push_back(shape->get_intersection(other));
	}
}