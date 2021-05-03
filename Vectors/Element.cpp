#include "Element.h"


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
std::ostream& Element::ins(std::ostream& out) const{
	out << "X = " << this->x << std::endl;
	out << "Y = " << this->y << std::endl;
	out << "Z = " << this->z << std::endl;

	return out;

}
std::ostream& operator<<(std::ostream& lhs, const Element& rhs) {
	return rhs.ins(lhs);
}