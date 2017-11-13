/**
* Defines a generic Point class represented by two coordinates.
*/

#pragma once

namespace Intersections {

template <class T>
class Point
{
public:

	/** 
	*  @Constructor
	*
	*  @param x the first coordinate of the point
	*  @param y the second coordinate of the point
	*/
	Point(T x, T y) : x(x), y(y) {}

	/** 
	*  Return the x coordinate of the point.
	*
	*  @return the first coordinate.
	*/
	T get_x_coord() const { return x; }

	/**
	*  Return the y coordinate of the point.
	*
	*  @return the second coordinate.
	*/
	T get_y_coord() const { return y; }
private:
	T x, y;
};

}
