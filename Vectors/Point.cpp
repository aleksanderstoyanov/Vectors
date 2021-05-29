#include "Point.h"

Point::Point(double x, double y, double z)
{
	setX(x);
	setY(y);
	setZ(z);
}

Point::Point(const Point& rhs)
{
	setX(rhs.getX());
	setY(rhs.getY());
	setZ(rhs.getZ());
}
Point& Point::operator=(const Point& rhs)
{
	if (this != &rhs)
	{
		setX(rhs.getX());
		setY(rhs.getY());
		setZ(rhs.getZ());
	}
	return *this;
}
Point::~Point()
{
	//Point destructor;
}
int Point::quadrant() const
{
	if (getX() > 0 and getY() > 0 and getZ() > 0) return 1;
	else if (getX() < 0 and getY() > 0 and getZ() > 0) return 2;
	else if (getX() < 0 and getY() < 0 and getZ() > 0) return 3;
	else if (getX() > 0 and getY() < 0 and getZ() > 0) return 4;
	else if (getX() > 0 and getY() > 0 and getZ() < 0) return 5;
	else if (getX() < 0 and getY() > 0 and getZ() < 0) return 6;
	else if (getX() < 0 and getY() < 0 and getZ() < 0) return 7;
	else if (getX() > 0 and getY() < 0 and getZ() < 0) return 8;
	else return -1;
	return 0;
}
std::ostream& Point::ins(std::ostream& out) const
{
	out << "X = " << getX() << std::endl;
	out << "Y = " << getY() << std::endl;
	out << "Z = " << getZ() << std::endl;
	return out;
}

std::istream& Point::ext(std::istream& in)
{
	double x, y, z;
	std::cout << "Enter x: ";
	in >> x;
	std::cout << "Enter y: ";
	in >> y;
	std::cout << "Enter z: ";
	in >> z;
	setX(x);
	setY(y);
	setZ(z);
	return in;
}

bool Point::operator==(const Point& rhs) const
{
	return (getX() == rhs.getX() and getY() == rhs.getY() and getZ() == rhs.getZ());
}



std::ostream& operator<<(std::ostream& lhs, const Point& rhs)
{
	return rhs.ins(lhs);
}

std::istream& operator>>(std::istream& lhs, Point& rhs)
{
	return rhs.ext(lhs);
}
