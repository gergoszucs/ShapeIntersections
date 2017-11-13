/**
* Read shapes from a text file and calculate their intersection points.
*/

#pragma once

#include "shape.h"
#include <vector>

namespace Intersections {

class ShapeReader
{
public:
	/**
	*  @Constructor
	*/
	ShapeReader() { read_shapes(); };

	/**
	*  Getter for the vector of intersections.
	*
	*  @return the vector of intersections
	*/
	const std::vector<Point<float>>&  get_intersections() const { return intersections; };
private:
	std::list<Shape*> shapes;
	std::vector<Point<float>> intersections;

	/**
	*  Read shape objects from the console.
	*/
	void read_shapes();
};

}
