#include "circle.h"
#include "line.h"

std::list<Intersections::Point<float>> Intersections::Circle::find_intersections(const Shape* shape) const 
{
	if (const Line* other = dynamic_cast<const Line*>(shape)) {
		// The line class already has this logic implemented
		return other->find_intersections(this);
	}
	else if (const Circle* other = dynamic_cast<const Circle*>(shape)) {
		return find_circle_intersection(other);
	}

	// Should not happen with a correct input
	return {};
}

std::list<Intersections::Point<float>> Intersections::Circle::find_circle_intersection(const Circle* other) const 
{
	// dx and dy are the vertical and horizontal distances between the circle centers.
	int dx = other->get_center().get_x_coord() - center.get_x_coord();
	int dy = other->get_center().get_y_coord() - center.get_y_coord();
	// Determine the straight-line distance between the centers.
	float d = (float)hypot(dx, dy);

	if (d > (radius + other->get_radius())) {
		// Circles does not intersect
		return {};
	}
	else if (d < fabs(radius - other->get_radius())) {
		// One of the circles contains the other
		return {};
	}

	// 'point 2' is the point where the line through the circle intersection points crosses the line between the circle centers.
	// Determine the distance from point 0 to point 2.
	float a = ((radius * radius) - (other->get_radius() * other->get_radius()) + (d * d)) / (2.0 * d);

	// Determine the coordinates of point 2.
	float x2 = center.get_x_coord() + (dx * a / d);
	float y2 = center.get_y_coord() + (dy * a / d);

	// Determine the distance from point 2 to either of the intersection points.
	float h = sqrt((radius * radius) - (a * a));

	// Now determine the offsets of the intersection points from point 2.
	float rx = -dy * (h / d);
	float ry = dx * (h / d);

	// Determine the absolute intersection points.
	float p1x = x2 + rx;
	float p2x = x2 - rx;
	float p1y = y2 + ry;
	float p2y = y2 - ry;

	if (p1x == p2x && p1y == p2y) {
		// The points are the same -> there is only one intersection
		return { Point<float>(p1x, p1y) };
	}
	else {
		return{ Point<float>(p1x, p1y), Point<float>(p2x, p2y) };
	}
}
