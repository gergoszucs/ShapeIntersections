#pragma once

namespace Intersections {

template <class T>
class Point
{
public:
	Point(T x, T y) : x(x), y(y) {}
	const T get_x_coord() const { return x; }
	const T get_y_coord() const { return y; }
private:
	T x, y;
};

}
