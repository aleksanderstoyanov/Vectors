#ifndef VECTOR_H
#define VECTOR_H
#include "Point.h"
#include"VectorLengthException.h" 

class Vector : virtual public Point
{
public:
	//BIG FIVE
	//There were two default constructors
 // from 3 values
	Vector(double = 0., double = 0., double = 0.);
	Vector(Point, Point); // from 2 points
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	virtual ~Vector();

	// inserter
	virtual std::ostream& ins(std::ostream&) const;

	// extracter 
	virtual std::istream& ext(std::istream&);

	// functions
	double length() const;
	Vector direction() const;
	bool isNull() const;
	bool parallel(const Vector&) const;
	bool perpendicular(const Vector&) const;

	// operators
	Vector operator+(const Vector&) const;
	Vector operator-(const Vector&) const;
	Vector operator*(double) const; // vector * number // vector -> lhs
	double operator*(const Vector&) const; // scalar
	Vector operator^(const Vector&) const; // vector product
	double operator()(const Vector&, const Vector&); // triple product

};

Vector operator*(double, const Vector&); // number * vector // vector -> rhs
#endif


