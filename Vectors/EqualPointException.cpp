#include "EqualPointException.h"

EqualPointException::EqualPointException(double x, double y, double z)
	:exception("EqualPointException thrown"),x(x),y(y),z(z)
{
	
	std::cout << "Point: (" << x << ", " << y << ", " << z << ")" << std::endl;
}
