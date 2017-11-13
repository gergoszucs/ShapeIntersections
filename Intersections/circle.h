/**
* Declares a Circle class represented with the center point and the radius.
*/

#pragma once

#include "shape.h"

namespace Intersections {

class Circle: public Shape
{
public:
	/**
	*  @Constructor
	*
	*  @param x the first coordinate of the center point of the circle
	*  @param y the second coordinate of the center point of the circle
	*  @param radius the radius of the circle
	*/
	Circle(int x, int y, int radius) : center(x, y), radius(radius) {}

	/**
	*  Return the list of points containing the intersection point(s) of the two shapes, if any.
	*
	*  @param other another shape object to calculate intersections against
	*  @return the list containing the intersection points, if any
	*/
	std::list<Point<float>> find_intersections(const Shape* shape) const override;

	/**
	*  Getter for the center point of the circle.
	*
	*  @return the center point of the circle
	*/
	const Point<int>& get_center() const { return center; }

	/**
	*  Return the list of points containing the intersection point(s) of the two shapes, if any.
	*
	*  @param other another shape object to calculate intersections against
	*  @return the list containing the intersection points, if any
	*/
	int get_radius() const { return radius; }
private:
	Point<int> center;
	int radius;

	/**
	*  Return the list of points containing the intersection point(s) of the two shapes, if any.
	*
	*  @param other another shape object to calculate intersections against
	*  @return the list containing the intersection points, if any
	*/
	std::list<Point<float>> find_circle_intersection(const Circle* other) const;
};

}
