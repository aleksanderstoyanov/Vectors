#include "Element.h"

//Getters
int Element::setX(double x) {
	this->x = x;
}
int Element::setY(double y) {
	this->y = y;
}
int Element::setZ(double z) {
	this->z = z;
}

//Setters
double Element::getX()const {
	return this->x;
}
double Element::getY()const {
	return this->y;
}
double Element::getZ()const {
	return this->z;
}

//Big five
Element::Element(double x, double y, double z) :x(0.), y(0.), z(0.) {

}
Element::Element(const Element& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {

}
Element::~Element() {
	std::cout << "Element destructor" << std::endl;
}
Element& Element::operator=(const Element& rhs) {
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}

	return *this;
}
