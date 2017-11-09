#pragma once

#include "shape.h"

namespace Intersections {

class Line: public Shape
{
public:
	Line(int x1, int y1, int x2, int y2);
	bool is_intersecting (const Shape* other) const override;
	Point<double> get_intersection(const Shape* other) const override;
	const Point<int>& get_x_point() const { return x; }
	const Point<int>& get_y_point() const { return y; }
	const double get_slope() const { return m; }
	const double get_y_intercept() const { return b; }
private:
	// Slope-intercept form y = mx + b
	// m is the slope of the line
	// b is the y intercept
	Point<int> x, y;
	double m, b;
};

}
