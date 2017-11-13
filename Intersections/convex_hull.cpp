#include "convex_hull.h"

bool Intersections::ConvexHull::is_ccw(Point<float> a, Point<float> b, Point<float> c) const
{
	return (c.get_y_coord() - a.get_y_coord()) * (b.get_x_coord() - a.get_x_coord())
		> (b.get_y_coord() - a.get_y_coord()) * (c.get_x_coord() - a.get_x_coord());
}

bool Intersections::ConvexHull::are_colinear(Point<float> a, Point<float> b, Point<float> c) const
{
	return fabs((a.get_y_coord() - b.get_y_coord()) * (a.get_x_coord() - c.get_x_coord()) 
		- (a.get_y_coord() - c.get_y_coord()) * (a.get_x_coord() - b.get_x_coord())) <= 1e-6;
}

void Intersections::ConvexHull::find_convex_hull(std::vector<Point<float>> points) 
{
	int num_of_points = points.size();

	// There must be at least 3 points
	if (num_of_points < 3) {
		return;
	}

	// Check if points are collinear
	bool are_all_colinear = false;

	for (int i = 1; i < num_of_points - 3; i+=3) {
		if (!are_colinear(points[i], points[i + 1], points[i + 2])) {
			break;
		}
		are_all_colinear = true;
	}

	// Check the last 3 points in case the for loop would miss them
	if (are_all_colinear && are_colinear(points[num_of_points - 3], points[num_of_points - 2], points[num_of_points - 1])) {
		return;
	}

	// Find the leftmost point
	int left_most_point = 0;
	for (int i = 1; i < num_of_points; i++) {
		if (points[i].get_x_coord() < points[left_most_point].get_x_coord()) {
			left_most_point = i;
		}
	}

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again.  This loop runs O(h)
	// times where h is number of points in result or output.
	int current_point = left_most_point, q;

	do {
		// Add current point to result
		hull_points.push_back(points[current_point]);

		// Search for a point 'q' such that orientation(p, x,
		// q) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		q = (current_point + 1) % num_of_points;
		for (int i = 0; i < num_of_points; i++)
		{
			// If i is more counterclockwise than current q, then update q
			if (is_ccw(points[current_point], points[i], points[q])) {
				q = i;
			}	
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		current_point = q;
	} while (current_point != left_most_point); // While we don't come to first point
}

float Intersections::ConvexHull::get_area() const 
{
	if (hull_points.size() == 0) {
		return 0;
	}

	float a = 0.0, b = 0.0;

	// Sum the cross products around each vertex
	for (int i = 0; i < hull_points.size() - 1; i++) {
		a += hull_points[i].get_x_coord() * hull_points[i + 1].get_y_coord();
		b += hull_points[i].get_y_coord() * hull_points[i + 1].get_x_coord();
	}

	a += hull_points[hull_points.size() - 1].get_x_coord() * hull_points[0].get_y_coord();
	b += hull_points[hull_points.size() - 1].get_y_coord() * hull_points[0].get_x_coord();

	return (a - b) / 2;
}
