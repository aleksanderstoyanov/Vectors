#ifndef Line_hh
#define Line_hh
#include <iostream>
#include <exception>
#include <cmath>
#include <fstream>
#include "Vector.h"
#include "Helper.h"

class Line : public Vector {


private:
	
	Point findCrossingPoint(Line&);
	Point point;
	Point point2;
public:

	double parametricEquations[3] = { 0.,0.,0. };
	Line();
	Line(const Point&, const Vector&);
	Line(const Point&, const Point&);
	Line(const Line&);
	virtual ~Line();
	Line& operator= (const Line&);

	//functionalities
	
	Line& findParametricEquation(int t);
	Line& findParametricEquation(double t);
	Vector lineDirection() const;
	Vector findNormalVector() const;
	double findAngleOfBetweenTwoLines(const Line&)const;
	char* numberToChar(double)const;

	//predefined operators

	//TO DO: Decide on whether an operator should be in class, or outside
	bool operator +(const Point&)const;
	bool operator ||(const Line&)const;
	bool operator ==(const Line&)const;
	bool operator &&(const Line&)const;
	bool operator !=(const Line&)const;
	bool operator |(const Line&)const;

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

	Point getPoint1()const;
};

#endif // !Line_hh


