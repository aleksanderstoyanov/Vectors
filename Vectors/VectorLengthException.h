#ifndef VectorLengthException_hh
#define VectorLengthException_hh
#include <iostream>
#include <exception>

class VectorLengthException : public std::exception {

public:
	VectorLengthException(double, double, double);

private:
	double x, y, z;
};

#endif // !VectorLengthException_hh
