#pragma once

#include "point.h"

namespace Intersections {

class Shape
{
public:
	virtual bool is_intersecting(const Shape* other) const = 0;
	virtual Point<double> get_intersection(const Shape* other) const = 0;
};

}
