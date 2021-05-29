#include"Vector.h"



Vector::Vector(double x, double y, double z)  // from 3 values
	: Point(x, y, z)
{
	setX(x);
	setY(y);
	setZ(z);
}

Vector::Vector(Point A, Point B)  // from 2 points
{
	setX(B.getX() - A.getX());
	setY(B.getY() - A.getY());
	setZ(B.getZ() - A.getZ());
}

Vector::Vector(const Vector& rhs)
	: Point(rhs.getX(), rhs.getY(), rhs.getZ()) 
{
	setX(rhs.getX());
	setY(rhs.getY());
	setZ(rhs.getZ());
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		Point::operator=(rhs); 
		setX(rhs.getX());
		setY(rhs.getY());
		setZ(rhs.getZ());
	}
	return *this;
}

Vector::~Vector()
{
	//Point::~Point();
	//Calling destructor of Vector;
}

// inserter
std::ostream& Vector::ins(std::ostream& out) const
{
	out << "Vector coordinates:\n";
	out << "X = " << getX() << std::endl;
	out << "Y = " << getY() << std::endl;
	out << "Z = " << getZ() << std::endl;
	return out;
}

// extracter 
std::istream& Vector::ext(std::istream& in)  //  2 options: 1)by 3 values or 2)by 2 Points
{
	std::cout << "Please choose an option to enter a Vector\n";
	std::cout << "Press 1 -> to enter by 3 values \n";
	std::cout << "Press 2 -> to enter by 2 Points\n";
	int option;
	in >> option;
	while (option != 1 and option != 2)
	{
		std::cout << "Invalid input for the menu!\n";
		std::cout << "Please choose an option to enter a Vector\n";
		std::cout << "Press 1 -> to enter by 3 values \n";
		std::cout << "Press 2 -> to enter by 2 Points\n";
		in >> option;
	}
	if (option == 1) Point::ext(in);
	else if (option == 2)
	{
		Point A;
		Point B;
		std::cout << "Please enter the coordinates for the first Point\n";
		in >> A;
		std::cout << "Please enter the coordinates for the second Point\n";
		in >> B;
		setX(B.getX() - A.getX());
		setY(B.getY() - A.getY());
		setZ(B.getZ() - A.getZ());
	}
	return in;
}

// functions
double Vector::length() const
{
	return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

Vector Vector::direction() const
{
	return Vector(getX() / length(), getY() / length(), getZ() / length());
}

bool Vector::isNull() const
{
	return (getX() == 0 and getY() == 0 and getZ() == 0);
}

bool Vector::parallel(const Vector& rhs) const   // throws exception !!
{
	if (rhs.isNull() || this->isNull())
	{
		std::cout << "One of the vectors is a null Vector\n";
		std::cout << "Cannot compare null vectors\n";
		throw VectorLengthException(rhs.getX(), rhs.getY(), rhs.getZ());
	}
	else
	{
		return (getX() / rhs.getX() == getY() / rhs.getY() == getZ() / rhs.getZ());
	}
}

bool Vector::perpendicular(const Vector& rhs) const  // throws exception !!
{
	if (rhs.isNull() || this->isNull())
	{
		std::cout << "One of the vectors is a null Vector\n";
		std::cout << "Cannot compare null vectors\n";
		throw VectorLengthException(rhs.getX(), rhs.getY(), rhs.getZ());
	}
	else
	{
		return ((getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ()) == 0);
	}
}

// operators
Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(getX() + rhs.getX(), getY() + rhs.getY(), getZ() + rhs.getZ());
}

Vector Vector::operator-(const Vector& rhs) const
{
	return Vector(getX() - rhs.getX(), getY() - rhs.getY(), getZ() - rhs.getZ());
}

Vector Vector::operator*(double n) const // vector * number // vector -> lhs
{
	return Vector(getX() * n, getY() * n, getZ() * n);
}

double Vector::operator*(const Vector& rhs) const // scalar
{
	return (getX() * rhs.getX() + getY() * rhs.getY() + getZ() * rhs.getZ());
}

Vector Vector::operator^(const Vector& rhs) const // vector product
{
	//a ∧ v = (y.v3 − z.v2, −x.v3 + z.v1, x.v2 − y.v1).
	Vector result = Vector(getY() * rhs.getZ() - (getZ() * rhs.getY()), -getX() * rhs.getZ() + getZ() * rhs.getX(), getX() * rhs.getY() - getY() * rhs.getX());
	return result;
}

double Vector::operator()(const Vector& v, const Vector& w)  // triple product
{
	double det1, det2, det3, determinant, matrix[3][3];
	/*(u × v) · w = u1 u2 u3
					v1 v2 v3
					w1 w2 w3    */

					// Fill the matrix
	matrix[0][0] = getX();
	matrix[0][1] = getY();
	matrix[0][2] = getZ();
	matrix[1][0] = v.getX();
	matrix[1][1] = v.getY();
	matrix[1][2] = v.getZ();
	matrix[2][0] = w.getX();
	matrix[2][1] = w.getY();
	matrix[2][2] = w.getZ();

	//Calculate through the first row
	det1 = ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]));
	det2 = ((matrix[1][0] * matrix[2][2]) - (matrix[2][0] * matrix[1][2]));
	det3 = ((matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1]));

	determinant = ((matrix[0][0] * det1) - (matrix[0][1] * det2) + (matrix[0][2] * det3));
	return determinant;
}

Vector operator*(double n, const Vector& rhs)  // number * vector  // vector -> rhs
{
	return Vector(rhs.getX() * n, rhs.getY() * n, rhs.getZ() * n);
}
