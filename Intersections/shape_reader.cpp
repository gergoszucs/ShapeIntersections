#include "shape_reader.h"
#include <iostream>
#include "line.h"
#include "circle.h"

void Intersections::ShapeReader::read_shapes()
{
	int shapeCount, x1, y1, x2, y2, radius;
	char type;
	Shape* newShape;

	std::cin >> shapeCount;

	for (int i = 0; i < shapeCount; i++) {
		std::cin >> type;

		// Read a line shape
		if (type == 'L') {
			std::cin >> x1 >> y1 >> x2 >> y2;
			newShape = new Line(x1, y1, x2, y2);
		}
		// Read a circle shape
		else {
			std::cin >> x1 >> y1 >> radius;
			newShape = new Circle(x1, y1, radius);
		}

		// Calculate intersections for each new shape over all of the existing ones
		for (auto shape : shapes) {
			for (auto intersection : newShape->find_intersections(shape)) {
				intersections.push_back(intersection);
			}
		}

		shapes.push_back(newShape);
	}
}
