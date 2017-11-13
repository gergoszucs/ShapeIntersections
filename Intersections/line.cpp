#include "line.h"
#include <math.h>
#include "circle.h"

Intersections::Line::Line(int x1, int y1, int x2, int y2) : x(x1, y1), y(x2,y2) 
{
	m = (float)(y2 - y1) / (float)(x2 - x1);
	b = y1 - (m * x1);
}

std::list<Intersections::Point<float>> Intersections::Line::find_intersections(const Shape* shape) const 
{
	if (const Line* other = dynamic_cast<const Line*>(shape)) {
		if (this->is_intersecting_with_line(other)) {
			return {this->find_line_intersection(other)};
		}
		else {
			return {};
		}
	}
	else if (const Circle* other = dynamic_cast<const Circle*>(shape)) {
		return find_circle_intersection(other);
	}

	// Should not happen with a correct input
	return {};
}

bool Intersections::Line::is_ccw(Point<int> p, Point<int> q, Point<int> r) const
{
	return (r.get_y_coord() - p.get_y_coord()) * (q.get_x_coord() - p.get_x_coord()) 
		> (q.get_y_coord() - p.get_y_coord()) * (r.get_x_coord() - p.get_x_coord());
}

bool Intersections::Line::is_intersecting_with_line(const Line* other) const 
{
	// Two lines intersect if and only if points A and B are separated by segment CD and points C and D are separated by segment AB
	// If points A and B are separated by segment CD then ACD and BCD should have opposite orientation meaning either ACD or BCD is counterclockwise but not both
	return is_ccw(x, other->get_x_point(), other->get_y_point()) != is_ccw(y, other->get_x_point(), other->get_y_point())
		&& is_ccw(x, y, other->get_x_point()) != is_ccw(x, y, other->get_y_point());
}

Intersections::Point<float> Intersections::Line::find_line_intersection(const Line* other) const 
{
	// Solve the slope-intercept equation for x (y = mx + b)
	float x = (other->get_y_intercept() - b) / (m - other->get_slope());
	// Plug x into the equation for y
	float y = m * x + b;

	return Point<float>(x, y);
}

std::list<Intersections::Point<float>> Intersections::Line::find_circle_intersection(const Circle* other) const 
{
	// Direction vector of line segment, from start to end
	Point<int> d = Point<int>(y.get_x_coord() - x.get_x_coord(), y.get_y_coord() - x.get_y_coord());
	// Line segment from center sphere to line start
	Point<int> f = Point<int>(x.get_x_coord() - other->get_center().get_x_coord(), x.get_y_coord() - other->get_center().get_y_coord());

	int a = d.get_x_coord() * d.get_x_coord() + d.get_y_coord() * d.get_y_coord();
	int b = 2 * (f.get_x_coord() * d.get_x_coord() + f.get_y_coord() * d.get_y_coord());
	int c = (f.get_x_coord() * f.get_x_coord() + f.get_y_coord() * f.get_y_coord()) - other->get_radius() * other->get_radius();
	float discriminant = b*b - 4 * a*c;

	if (discriminant < 0) {
		// No result for the equation -> no intersection
		return {};
	}
	else {
		discriminant = sqrt(discriminant);

		float t1 = (-b - discriminant) / (2 * a);
		float t2 = (-b + discriminant) / (2 * a);

		// Calculate the 2 possible intersection points by substituting t_x into the parametric equation
		Point<float> p1(x.get_x_coord() + t1 * d.get_x_coord(), x.get_y_coord() + t1 * d.get_y_coord());
		Point<float> p2(x.get_x_coord() + t2 * d.get_x_coord(), x.get_y_coord() + t2 * d.get_y_coord());

		if (t1 >= 0 && t1 <= 1)
		{
			if (t2 >= 0 && t2 <= 1)
			{
				return { p1, p2 };
			}
			return { p1 };
		}
		else if (t2 >= 0 && t2 <= 1)
		{
			return { p2 };
		}

		return {};
	}
}
