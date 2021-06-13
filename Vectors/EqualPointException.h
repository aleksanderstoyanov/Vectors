#ifndef EqualPointException_hh
#define EqualPointException_hh
#include <iostream>
#include <exception>

class EqualPointException :public std::exception {

private:
	double x, y, z;
public:
	EqualPointException(double, double, double);
};

#endif // !EqualPointException_hh
