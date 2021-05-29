#include "VectorLengthException.h"

VectorLengthException::VectorLengthException(double x, double y, double z)
	:exception("VectorLengthException thrown"), x(x), y(y), z(z)
{
	std::cout << "Vector( " << x << ", " << y << ", " << z << " )" << std::endl;
}

