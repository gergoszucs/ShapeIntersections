#include "line.h"
#include "circle.h"

Intersections::Line::Line(int x1, int y1, int x2, int y2) : x(x1, y1), y(x2,y2) {
	m = (double)(y2 - y1) / (double)(x2 - x1);
	b = y1 - (m * x1);
}

bool Intersections::Line::is_intersecting(const Shape* shape) const {
	if (const Line* other = dynamic_cast<const Line*>(shape)) {
		int A0 = x.get_x_coord();
		int B0 = x.get_y_coord();
		int A1 = y.get_x_coord();
		int B1 = y.get_y_coord();
		int A2 = other->get_x_point().get_x_coord();
		int B2 = other->get_x_point().get_y_coord();
		int A3 = other->get_y_point().get_x_coord();
		int B3 = other->get_y_point().get_y_coord();

		if ((((A2 - A0)*(B1 - B0) - (B2 - B0)*(A1 - A0)) * ((A3 - A0)*(B1 - B0) - (B3 - B0)*(A1 - A0))) <= 0
			&&
			(((A0 - A2)*(B3 - B2) - (B0 - B2)*(A3 - A2)) * ((A1 - A2)*(B3 - B2) - (B1 - B2)*(A3 - A2))) <= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (const Circle* other = dynamic_cast<const Circle*>(shape)) {

	}
	
}

Intersections::Point<double> Intersections::Line::get_intersection(const Shape* shape) const {
	double x, y;

	if (const Line* other = dynamic_cast<const Line*>(shape)) {
		x = (other->get_y_intercept() - b) / (m - other->get_slope());
		y = m * x + b;
	}
	else if (const Circle* other = dynamic_cast<const Circle*>(shape)) {
		x = 2.0;
		y = 2.0;
	}
	// else - raise ivalid type exception
	
	return Point<double>(x, y);
}