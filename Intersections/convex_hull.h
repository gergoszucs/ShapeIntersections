/**
* Create and calculate the points and/or the area of a convex hull.
*/

#pragma once

#include <vector>
#include "point.h"

namespace Intersections {

class ConvexHull
{
public:
	/**
	*  @Constructor
	*
	*  @param points a vector containing the points we want to calculate on
	*/
	ConvexHull(const std::vector<Point<float>>& points) { find_convex_hull(points); }

	/**
	*  Getter for the vector of points containing the calculated hull points.
	*
	*  @return the vector of points
	*/
	const std::vector<Point<float>>& get_hull_points() const { return hull_points; };

	/**
	*  Getter for the area of the conbex hull represented by the points.
	*
	*  @return the area of the hull.
	*/
	float get_area() const;
private:
	std::vector<Point<float>> hull_points;

	/**
	*  Find the points which define the convex hull using Jarvis’s Algorithm.
	*
	*  @param the points which the hull must be calculated on
	*/
	void find_convex_hull(std::vector<Point<float>> points);

	/**
	*  Determines if 3 points are in a counter clockwise order.
	*
	*  @param a point one
	*  @param b point two
	*  @param c point three
	*  @return whether the order is counter clockwise
	*/
	bool is_ccw(Point<float> a, Point<float> b, Point<float> c) const;

	/**
	*  Determines if 3 points are colinear (lie on the same straight line).
	*
	*  @param a point one
	*  @param b point two
	*  @param c point three
	*  @return whether the points are colinear
	*/
	bool are_colinear(Point<float> a, Point<float> b, Point<float> c) const;
};

}
