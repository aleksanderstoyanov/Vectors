#include "Line.h"


Line::Line() :point(Point(0., 0., 0.)) {

}

Line::Line(const Point& p, const Vector& v) : point(p) {
	this->setX(v.getX());
	this->setY(v.getY());
	this->setZ(v.getZ());

}
Line::Line(const Point& p, const Point& p2) {
	this->point = p;

	this->setX(p2.getX() - p.getX());
	this->setY(p2.getY() - p.getY());
	this->setZ(p2.getZ() - p.getZ());
	this->point2 = p2;
}
Line::Line(const Line& copy) : point(copy.point) {
	this->setX(copy.getX());
	this->setY(copy.getY());
	this->setZ(copy.getZ());

}
Line::~Line() {

	//Calling destructor of line;
}
Line& Line::operator=(const Line& rhs) {
	if (this != &rhs)
	{
		this->point = rhs.point;
		this->setX(rhs.getX());
		this->setY(rhs.getY());
		this->setZ(rhs.getZ());
	}

	return *this;
}
Vector Line::lineDirection()const {
	if (!isNull())// to has a direction, vector should be non null vector
	{
		Vector v;
		v.setX(v.getX() / this->length());
		v.setY(v.getY() / this->length());
		v.setZ(v.getZ() / this->length());
		return v;
	}
	else
	{
		throw ("Exception! A null vector has no direction\n");
		return Vector();
	}
}
Vector Line::findNormalVector() const {

	Vector one(1, 0, 0);
	Vector slope(getX(), getY(), getZ());
	Vector n = one ^ slope;

	return n;
}

bool Line::operator+(const Point& rhs) const {
	double x = (rhs.getX() - point.getX()) / (point2.getX() - point.getX());
	double y = (rhs.getY() - point.getY()) / (point2.getY() - point.getY());
	double z = (rhs.getZ() - point.getZ()) / (point2.getZ() - point.getZ());
	return x == y == z;


}

bool Line::operator||(const Line& rhs)const {

	double x = getX() / rhs.getX();
	double y = getY() / rhs.getY();
	double z = getZ() / rhs.getZ();
	// if [ b1( - b2') - b2( - b1') ] = 0
	double tDivider = (getX() * (-rhs.getY()) - getY() * (-rhs.getX()));
	// if tDivider = 0 -> means that the system has no solution -> parallel lines

	if ((x - y<0.01) && y - z<0.01 && (tDivider- 0. < 0.01)) return true;
	return false;

	/*
	double angle = this->findAngleOfBetweenTwoLines(rhs);
	if ((angle - 0.) < 0.01) return true;
	return false;
	*/

}
Point Line::findCrossingPoint(Line& rhs)
{
	if ((*this && rhs) == false)
	{
		std::cout << "The two lines don't cross, so they cannot have a crossing point.\n";
		return Point();
	}
	else
	{
		// now we know that two inclines of the lines are not proportional
		double t, s;

		// have to solve the system
		//system: | a1 + b1t = a1' + b1's
		//        | a2 + b2t = a2' + b2's

		// if [ b1( - b2') - b2( - b1') ] = 0
		if ((getX() * (-rhs.getY()) - getY() * (-rhs.getX())) == 0) return Point();//means that the system has no solution -> parallel lines

		/// Find t :
		// t = [ (a1' - a1)(-b2') - (a2' - a2)(-b1') ] / [ b1(-b2') - b2( - b1') ]
		t = (rhs.point.getX() - point.getX()) * (-rhs.getY()) - (rhs.point.getY() - point.getY()) * (-rhs.getX())
			/ (getX() * (-rhs.getY()) - getY() * (-rhs.getX()));

		// Substitute t in the second system equation and 
		/// Find s :
		s = (getY() * t - rhs.point.getY() + point.getY()) / rhs.getY();

		rhs.findParametricEquation(s);
		return Point(rhs.parametricEquations[0], rhs.parametricEquations[1], rhs.parametricEquations[2]);
	}

}

bool Line::operator==(const Line& rhs)const {

	double first = getX() / rhs.getX();
	double second = getY() / rhs.getY();
	double third = getZ() / rhs.getZ();

	if (!(first == second && second == third)) return false;

	// if [ b1( - b2') - b2( - b1') ] = 0
	double res1 = getX() * -rhs.getY();
	double res2 = getY() * -rhs.getX();
	double tDivider = ((getX() * (-rhs.getY())) - (getY() * (-rhs.getX())));
	// if tDivider = 0 -> means that the system has no solution -> parallel lines

	if ((tDivider - 0.) < 0.01) return false;
	// else -> means that the system has infinite count of solutions -> coincident lines
	return true;
}
bool Line::operator &&(const Line& inputLine)const {


	if (this->operator||(inputLine))
	{
		return false;
	}
	Vector v1(getX(), getY(), getZ());
	Vector v2(inputLine.getX(), inputLine.getY(), inputLine.getZ());
	// (uxv).(p-q)=0 ?
	Vector crossProduct = v1 ^ v2;
	Vector displacementVector1 = Vector(point.getX(), point.getY(), point.getZ());
	Vector displacementVector2 = Vector(inputLine.point.getX(), inputLine.point.getY(), inputLine.point.getZ());
	Vector resultVector = displacementVector1 - displacementVector2;

	if (crossProduct.perpendicular(resultVector))
	{
		return true;
	}
	return false;


}
double Line::findAngleOfBetweenTwoLines(const Line& rhs) const {
	double res;
	Vector v = Vector(getX(), getY(), getZ());
	Vector v2 = Vector(rhs.getX(), rhs.getY(), rhs.getZ());
	res = (abs(v * v2)) / abs(v.length() * v2.length());

	return (asin(res) * 180.0 / 3.14);
}

char* Line::numberToChar(double num) const // if coordinates of Point are bigger than one digit number
{
	int tmp = (int)num;
	int cntDigits = 0;
	if (tmp == 0) cntDigits = 1;
	while (tmp != 0)
	{
		cntDigits++;
		tmp /= 10;
	}
	char* chNumber = new char[cntDigits + 1];
	tmp = (int)num; // just in case -> for not to change the coordinate of the Point
	int j = cntDigits - 1;
	for (int i = cntDigits; i > 0; i--)
	{
		chNumber[j--] = ((char)abs(tmp) % 10 + '0');
		tmp /= 10;
	}
	j = cntDigits;
	chNumber[j] = '\0'; // put the terminate zero in the end
	return chNumber;
	if (chNumber != nullptr) delete[] chNumber;
}


std::ostream& Line::ins(std::ostream& out)const {
	out << "Point: (" << this->point.getX() << ", " << this->point.getY() << ", " << this->point.getZ() << ")" << std::endl;
	this->point.ins(out);
	Vector v = Vector(this->getX(), this->getY(), this->getZ());
	v.ins(out);
	out << "Parametric equation: " << std::endl;
	out << "L: " << "x = " << this->point.getX() << " + " << this->getX() << "t" << ", y = " << this->point.getY() << " + " << this->getY() << "t" << ", z = " << this->point.getZ() << " + " << this->getZ() << "t" << std::endl;

	std::ofstream writer("line.html");
	std::string html = R"(<!DOCTYPE html>
		<html lang = "en">

		<head>

		<meta charset = "UTF-8">
		<meta http-equiv = "X-UA-Compatible" content = "IE=edge">
		<meta name = "viewport" content = "width=device-width, initial-scale=1.0">
		<title>Document</title>
		<style>
		#vector{

	 font-size: 68px;
	 margin-left: 590px;
	 color: green;
	}
#line{
position: relative;
border: none;
height: 5px;
background: black;
	margin-bottom: 45px;
width: 360px;
	}
	#coordinates-v{
	   color: green;
		margin-left: 590px;
	}
		#coordinates-p{
   margin-top: -30px;
			margin-left: 520px;
	}
		</style>
		</head>
		<body>
		<p id="coordinates-v">)";
	html += "V(";
	//------------Coordinates for Vector--------------
	std::string tmpX;
	tmpX = numberToChar(getX());
	for (int i = 0; i < tmpX.length(); i++)html += tmpX[i];
	html += ", ";
	std::string tmpY;
	tmpY = numberToChar(getY());
	for (int i = 0; i < tmpY.length(); i++)html += tmpY[i];
	html += ", ";
	std::string tmpZ;
	tmpZ = numberToChar(getZ());
	for (int i = 0; i < tmpZ.length(); i++)html += tmpZ[i];
	html += ") </p>\n";
	html += R"(
	
		<div>
		<span id = "vector">&#8594;</span>
		<hr id="line">
		<p id="coordinates-p">)";
	//-----------Coordinates for Point----------------
	html += "P(";
	std::string pointTmpX;
	pointTmpX = numberToChar(point.getX());
	for (int i = 0; i < pointTmpX.length(); i++)html += pointTmpX[i];
	html += ", ";
	std::string pointTmpY;
	pointTmpY = numberToChar(point.getY());
	for (int i = 0; i < pointTmpY.length(); i++)html += pointTmpY[i];
	html += ", ";
	std::string pointTmpZ;
	pointTmpZ = numberToChar(point.getZ());
	for (int i = 0; i < pointTmpZ.length(); i++)html += pointTmpZ[i];
	html += ") </p>\n";
	html += R"(
		</div>
		</body>
		</html>)";

	writer << html;
	writer.close();
	return out;

}
std::ostream& operator << (std::ostream& lhs, const Line& rhs) {
	return rhs.ins(lhs);
}
Line& Line::findParametricEquation(double t) {
	//x = a1 + b1t
	double xEquation = (this->point.getX() + getX()) * t;
	//y = a2 + b2t
	double yEquation = (this->point.getY() + getY()) * t;
	//z = a3 + b3t
	double zEquation = (this->point.getZ() + getZ()) * t;
	this->parametricEquations[0] = xEquation;
	this->parametricEquations[1] = yEquation;
	this->parametricEquations[2] = zEquation;
	return *this;
}
Line& Line::findParametricEquation(int t) {
	if (t != 0 && t != 1) throw std::invalid_argument("Invalid value for t");

	//Намираме свързаният вектор, който ще ни служи за наклон на отсечката
	Vector AA = lineDirection();
	//x = a1 + b1t
	double xEquation = (this->point.getX() + AA.getX()) * t;
	//y = a2 + b2t
	double yEquation = (this->point.getY() + AA.getY()) * t;
	//z = a3 + b3t
	double zEquation = (this->point.getZ() + AA.getZ()) * t;
	this->parametricEquations[0] = xEquation;
	this->parametricEquations[1] = yEquation;
	this->parametricEquations[2] = zEquation;
	return *this;


}
bool Line::operator|(const Line& line2)const {

	Vector slope1 = Vector(this->getX(), this->getY(), this->getZ());
	Vector slope2 = Vector(line2.getX(), line2.getY(), line2.getZ());

	return slope1.perpendicular(slope2);


}
bool Line::operator!=(const Line& line2)const {
	if (this->operator||(line2) == false && this->operator&&(line2) == false)
	{
		return true;
	}
	return false;
}
std::istream& Line::ext(std::istream& in) {
	int option;
	std::cout << "Choose between 1 and 2" << std::endl;
	std::cout << "1. Initialize Line with point and vector" << std::endl;
	std::cout << "2.Initialize Line with two points" << std::endl;
	std::cin >> option;
	while (true)
	{
		if (option == 1 || option == 2)
		{
			break;
		}
		std::cout << "Not a valid option try again !" << std::endl;
		std::cin >> option;
	}
	if (option == 1)
	{
		std::cout << "Enter coordinates for point: " << std::endl;
		point.ext(in);
		Vector v = Vector();
		v.ext(in);
		setX(v.getX());
		setY(v.getY());
		setZ(v.getZ());
	}
	else {
		Point p1;
		Point p2;
		std::cout << "Enter coordinates for first point: " << std::endl;
		in >> p1;
		std::cout << "Enter coordinates for second point: " << std::endl;
		in >> p2;
		//Initialize points
		this->point = p1;
		this->point2 = p2;
		//Initialize vector
		this->setX(p2.getX() - p1.getX());
		this->setY(p2.getY() - p1.getY());
		this->setZ(p2.getZ() - p1.getZ());
	}

	return in;
}
std::istream& operator >> (std::istream& lhs, Line& rhs) {
	return rhs.ext(lhs);
};
Point Line::getPoint1()const {
	return this->point;
}