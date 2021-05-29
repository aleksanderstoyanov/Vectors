#ifndef POINT_H
#define POINT_H
#include "Element.h"

class Point : public Element
{
public:
	// BIG FIVE
	Point(double = 0., double = 0., double = 0.);
	Point(const Point&);
	Point& operator=(const Point&);
	virtual ~Point();

	// inserter
	virtual std::ostream& ins(std::ostream&) const;

	//extracter
	virtual std::istream& ext(std::istream&);

	//extra
	bool operator==(const Point&) const;

	//redefining a pure virtual func
	virtual int quadrant() const;

};

std::ostream& operator<<(std::ostream&, const Point&);

std::istream& operator>>(std::istream&, Point&);

#endif

