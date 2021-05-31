#ifndef Triangle_hh
#define Triangle_hh
#include "Vector.h"
#include"Helper.h"
#include "EqualPointException.h"
#include <string>
#include <fstream>

class Triangle :virtual public Point, public Vector
{

private:
	Point a, b, c;
public:
	//Big Five
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	virtual ~Triangle();
	Triangle& operator = (const Triangle&);

	// getters
	Point getA() const;
	Point getB() const;
	Point getC() const;


	//functionalities
	char* type()const;
	double area()const;
	double perimeter()const;
	Point medicenter()const;

	//TO DO: Implement quadrant function
	/*virtual int quadrant()const;*/

	//predefined operators
	bool operator <(const Point&)const;  // Triangle < Point
	bool operator >(const Point&)const;
	bool operator ==(const Point&)const;

	//streams
	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};


// Point < Triangle
bool operator <(const Point&, const Triangle&);
bool operator >(const Point&, const Triangle&);
bool operator ==(const Point&, const Triangle&);


#endif // !Triangle_hh

