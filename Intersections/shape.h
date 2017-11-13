/**
* Abstract shape class which declares one function to calculate intersections
* on any shape with any another shape
*/

#pragma once

#include <list>
#include "point.h"

namespace Intersections {

class Shape
{
public:
	/**
	*  Return the list of points containing the intersection point(s) of the two shapes, if any.
	*
	*  @param other another shape object to calculate intersections against
	*  @return the list containing the intersection points, if any
	*/
	virtual std::list<Point<float>> find_intersections(const Shape* other) const = 0;
};

}
