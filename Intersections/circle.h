#pragma once

#include "shape.h"

namespace Intersections {

class Circle: public Shape
{
public:
	Circle(int x, int y, int radius) : center(x, y), radius(radius) {}
	bool is_intersecting(const Shape* other) const override;
	Point<double> get_intersection(const Shape* other) const override;
	const Point<int>& get_center() const { return center; }
private:
	Point<int> center;
	int radius;
};

}
