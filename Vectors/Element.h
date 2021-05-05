#ifndef Element_hh
#define Element_hh
#include <iostream>
class Element {
private:
	//Coordinates
	double x, y, z;

public:

	//Big 5
	Element(double = 0., double = 0., double = 0.);
	Element(const Element&);
	~Element();
	Element& operator=(const Element&);

	// pure virtual
	virtual int quadrant() const=0;

	//getters
	double getX()const;
	double getY()const;
	double getZ()const;

	//setters
	int setX(double);
	int setY(double);
	int setZ(double);

	//predefine operator == ?

};

#endif // !Element_hh

