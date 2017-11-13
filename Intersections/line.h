/**
* Declares a Line class represented in the slope-intercept form.
*/

#pragma once

#include "shape.h"

namespace Intersections {

// Forward declaration to avoid circular injection, while still allowing the usage of Circle pointers.
class Circle;
class Line: public Shape
{
public:
	/**
	*  @Constructor
	*
	*  @param x1 the first coordinate of the first point
	*  @param y1 the second coordinate of the first point
	*  @param x2 the first coordinate of the second point
	*  @param y2 the second coordinate of the second point
	*/
	Line(int x1, int y1, int x2, int y2);

	/**
	*  Return the list of points containing the intersection point(s) of the two shapes, if any.
	*
	*  @param other another shape object to calculate intersections against
	*  @return the list containing the intersection points, if any
	*/
	std::list<Point<float>> find_intersections(const Shape* shape) const override;

	/**
	*  Getter for the starting point of the line.
	*
	*  @return the starting point of the line
	*/
	const Point<int>& get_x_point() const { return x; }

	/**
	*  Getter for the end point of the line.
	*
	*  @return the end point of the line
	*/
	const Point<int>& get_y_point() const { return y; }

	/**
	*  Getter for the slope of the line as in the slope-intercept form.
	*
	*  @return the slope of the line
	*/
	const float get_slope() const { return m; }

	/**
	*  Getter for the y-intercept of the line as in the slope-intercept form.
	*
	*  @return the y-intercept of the line
	*/
	const float get_y_intercept() const { return b; }
private:
	// Slope-intercept form y = mx + b
	// m is the slope of the line
	// b is the y-intercept
	Point<int> x, y;
	float m, b;

	/**
	*  Return whether the current line intersects another line.
	*
	*  @param other another line object to calculate intersections against
	*  @return whether there is an intersection or not
	*/
	bool is_intersecting_with_line(const Line* other) const;

	/**
	*  Find where the point of intersection for this line and the line argument.
	*
	*  @param other another line object to calculate intersections against
	*  @return the point of intersection
	*/
	Point<float> find_line_intersection(const Line* other) const;

	/**
	*  Find where the point of intersection(s) for this line and the circle argument.
	*
	*  @param other a circle object to calculate intersections against
	*  @return the list of intersections, if any
	*/
	std::list<Point<float>> find_circle_intersection(const Circle* other) const;

	/**
	*  Determines if 3 points are in a counter clockwise order.
	*
	*  @param p point one
	*  @param q point two
	*  @param r point three
	*  @return whether the order is counter clockwise
	*/
	bool is_ccw(Point<int> p, Point<int> q, Point<int> r) const;
};

}
