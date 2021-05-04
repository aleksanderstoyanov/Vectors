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
	virtual int print()const = 0;



	//predefine operator == ?

};

#endif // !Element_hh

