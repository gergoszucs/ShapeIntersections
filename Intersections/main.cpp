/**
* Test the different type of shape intersections, convex hull generation and area calculation.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "shape_reader.h"
#include "convex_hull.h"
#include "line.h"
#include "circle.h"

using namespace Intersections;

int main() 
{
	// Initialize a new shape reader and retrieve the calculated intersection points
	ShapeReader reader;
	std::vector<Point<float>> intersections = reader.get_intersections();
	
	std::cout << std::fixed << std::setprecision(4) << intersections.size() << std::endl;

	std::for_each(intersections.begin(), intersections.end(), 
		[](const Point<float>& p) {
			std::cout << p.get_x_coord() << " " << p.get_y_coord() << std::endl; 
	});

	// Create a convex hull object and generate the polygon from the intersection points
	ConvexHull convexHull(intersections);
	std::vector<Point<float>> hullPoints = convexHull.get_hull_points();
	std::cout << hullPoints.size() << std::endl;

	for (auto point : hullPoints) {
		std::cout << point.get_x_coord() << " " << point.get_y_coord() << std::endl;
	}

	std::cout << convexHull.get_area() << std::endl;
}
