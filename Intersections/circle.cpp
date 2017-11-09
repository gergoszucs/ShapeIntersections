#include "circle.h"

bool Intersections::Circle::is_intersecting(const Shape* other) const {
	return false;
}

Intersections::Point<double> Intersections::Circle::get_intersection(const Shape* other) const {
	return Point<double>(2,2);
}
