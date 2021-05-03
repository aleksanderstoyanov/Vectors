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

	//Getters pure virtual
	virtual double getX()const=0;
	virtual double getY()const=0;
	virtual double getZ()const=0;

	

   //predefine operator == ?
	virtual std::ostream& ins(std::ostream&)const;
};
std::ostream& operator <<(std::ostream&, const Element&);
#endif // !Element_hh

