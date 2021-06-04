#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H
#include "Vector.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include "Helper.h"

class Tetrahedron : public Vector, public Triangle
{
public:
	//BIG FIVE
	Tetrahedron();
	Tetrahedron(Point, Point, Point, Point);
	Tetrahedron(const Tetrahedron&);
	virtual ~Tetrahedron();
	Tetrahedron& operator=(const Tetrahedron&);

	//getters
	Point getA() const;
	Point getB() const;
	Point getC() const;
	Point getD() const;

	// other functions
	bool isRegular() const;
	bool isOrthocentric() const;
	double surfaceArea() const;
	double volume() const;

	virtual std::ostream& ins(std::ostream&)const;
	std::istream& ext(std::istream&);

	//redefined operators <, >, ==           Tetrahedron < Point    -> Tetrahedron = lhs
	bool operator<(const Point&) const;
	bool operator>(const Point&) const;
	bool operator==(const Point&) const;

private:
	Point A;
	Point B;
	Point C;
	Point D;

};

// Point < Tetrahedron  -> Point = lhs 
bool operator<(const Point&, const Tetrahedron&);
bool operator>(const Point&, const Tetrahedron&);
bool operator==(const Point&, const Tetrahedron&);


#endif


