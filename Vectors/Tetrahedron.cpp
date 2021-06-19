#include"Tetrahedron.h"
#include <fstream>

Tetrahedron::Tetrahedron()
	:A(Point()), B(Point()), C(Point()), D(Point())
{}

Tetrahedron::Tetrahedron(Point a, Point b, Point c, Point d)  // throws !!
	: A(a), B(b), C(c), D(d)
{
	if (A == B or A == C or A == D) throw EqualPointException(A.getX(), A.getY(), A.getZ());
	else if (B == C or B == D) throw EqualPointException(B.getX(), B.getY(), B.getZ());
	else if (C == D) throw EqualPointException(C.getX(), C.getY(), C.getZ());
}

Tetrahedron::Tetrahedron(const Tetrahedron& rhs)
	: A(rhs.A), B(rhs.B), C(rhs.C), D(rhs.D)
{}

Tetrahedron::~Tetrahedron()
{
	/*
	Vector::~Vector();
	Triangle::~Triangle();
	std::cout << "Destructor of Tetrahedron\n";
	*/
}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs)
{
	if (this != &rhs)
	{
		A = rhs.A;
		B = rhs.B;
		C = rhs.C;
		D = rhs.D;
	}
	return *this;
}

//getters
Point Tetrahedron::getA() const { return A; }
Point Tetrahedron::getB() const { return B; }
Point Tetrahedron::getC() const { return C; }
Point Tetrahedron::getD() const { return D; }



bool Tetrahedron::isRegular() const   // if all edges are equal => all four triangles are equilateral => Tetra is regular
{
	Vector AB(A, B);
	Vector BC(B, C);
	Vector AC(A, C);
	Vector AD(A, D);
	Vector BD(B, D);
	Vector CD(C, D);

	double lAB = AB.length();
	double lBC = BC.length();
	double lAC = AC.length();
	double lAD = AD.length();
	double lBD = BD.length();
	double lCD = CD.length();

	//if (AB.length() == BC.length() == AC.length() == AD.length() == BD.length() == CD.length()) return true; // delete this later
	if (lAB == lBC and lBC == lAC and lAC == lAD and lAD == lBD and lBD == lCD) return true;
	return false;
}

bool Tetrahedron::isOrthocentric() const
{
	/*A tetrahedron ABCD is orthocentric if and only if
	the sum of the squares of opposite edges is the same for the three pairs of opposite edges:
	 AB^2+CD^2 = AC^2+BD^2 = AD^2+BC^2 */
	Vector AB(A, B);
	Vector BC(B, C);
	Vector AC(A, C);
	Vector AD(A, D);
	Vector BD(B, D);
	Vector CD(C, D);
	double sqAB = AB.length() * AB.length();
	double sqCD = CD.length() * CD.length();
	double sqAC = AC.length() * AC.length();
	double sqBD = BD.length() * BD.length();
	double sqAD = AD.length() * AD.length();
	double sqBC = BC.length() * BC.length();
	//   AB^2+CD^2 =      AC^2+BD^2 =     AD^2+BC^2 
	if ((sqAB + sqCD) == (sqAC + sqBD) and (sqAC + sqBD) == (sqAD + sqBC))return true;
	return false;
}

double Tetrahedron::surfaceArea() const
{
	double S = 0.;
	if (isRegular()) // if regular use the basic formula
	{
		Vector AB(A, B);
		double edge = AB.length();
		double S = sqrt(3) * edge * edge;  // S = sqrt(3) * a^2
	}
	else   // if not, find the areas of all 4 different triangles
	{
		Triangle ABC(A, B, C);
		Triangle ABD(A, B, D);
		Triangle ACD(A, C, D);
		Triangle BCD(B, C, D);
		S = ABC.area() + ABD.area() + ACD.area() + BCD.area();
	}
	return S;
}

double Tetrahedron::volume() const
{
	double V = 0.;
	if (isRegular())   // for not to call redundant operations
	{
		Vector AB(A, B);
		double edge = AB.length();
		V = (sqrt(2) * edge * edge * edge) / 12;  // V = (sqrt(2) * edge^3) /12
	}
	else
	{
		Vector AB(A, B);
		Vector AC(A, C);
		Vector AD(A, D);
		V = abs(AB(AC, AD)) / 6;      // V = |triple product| / 6
	}
	return V;
}

bool Tetrahedron::operator>(const Point& P) const    // Tetrahedron > Point
													/// if Point is inside
	// IDEA: 1) find the medicenter of the base(ABC)
	//       2) divide Tetrahedron in 4 mini Tetrahedrons
	//       3) find their volumes
	//       4) check if their sum is equal to volume of the big Tetrahedron if(true) return true;
{

	Triangle ABC(A, B, C);
	Point M = ABC.medicenter();

	Tetrahedron ABMP(A, B, M, P);
	Tetrahedron BCMP(B, C, M, P);
	Tetrahedron ABPD(A, B, P, D);
	Tetrahedron CPBD(C, P, B, D);

	double volABMP = ABMP.volume();
	double volBCMP = BCMP.volume();
	double volABPD = ABPD.volume();
	double volCPBD = CPBD.volume();
	double volABCD = volume();
	double sum = volABMP + volBCMP + volABPD + volCPBD;

	if (volABCD - sum < 0.001) return true;
	return false;
}


bool Tetrahedron::operator<(const Point& P) const       // Tetrahedron < Point 
														/// if Point is outside
	// IDEA: 1) find the medicenter of the base(ABC)
	//       2) divide Tetrahedron in 4 mini Tetrahedrons
	//       3) find their volumes
	//       4) check if their sum is greater than volume of the big Tetrahedron if(true) return true;
{

	Triangle ABC(A, B, C);
	Point M = ABC.medicenter();

	Tetrahedron ABMP(A, B, M, P);
	Tetrahedron BCMP(B, C, M, P);
	Tetrahedron ABPD(A, B, P, D);
	Tetrahedron CPBD(C, P, B, D);

	double volABMP = ABMP.volume();
	double volBCMP = BCMP.volume();
	double volABPD = ABPD.volume();
	double volCPBD = CPBD.volume();
	double volABCD = volume();
	double sum = volABMP + volBCMP + volABPD + volCPBD;

	if (volABCD < sum) return true;
	return false;
}
bool Tetrahedron::operator==(const Point& P) const
{
	if (!(*this > P) and !(*this < P)) return true;
	return false;
}

bool operator<(const Point& P, const Tetrahedron& T)     // Point < Tetrahedron
														/// if Point is inside
{
	Triangle ABC(T.getA(), T.getB(), T.getC());
	Point M = ABC.medicenter();

	Tetrahedron ABMP(T.getA(), T.getB(), M, P);
	Tetrahedron BCMP(T.getB(), T.getC(), M, P);
	Tetrahedron ABPD(T.getA(), T.getB(), P, T.getD());
	Tetrahedron CPBD(T.getC(), P, T.getB(), T.getD());

	double volABMP = ABMP.volume();
	double volBCMP = BCMP.volume();
	double volABPD = ABPD.volume();
	double volCPBD = CPBD.volume();
	double volABCD = T.volume();
	double sum = volABMP + volBCMP + volABPD + volCPBD;

	if (volABCD - sum < 0.001) return true;
	return false;
}

bool operator>(const Point& P, const Tetrahedron& T)     // Point > Tetrahedron
														/// if Point is outside
{
	Triangle ABC(T.getA(), T.getB(), T.getC());
	Point M = ABC.medicenter();

	Tetrahedron ABMP(T.getA(), T.getB(), M, P);
	Tetrahedron BCMP(T.getB(), T.getC(), M, P);
	Tetrahedron ABPD(T.getA(), T.getB(), P, T.getD());
	Tetrahedron CPBD(T.getC(), P, T.getB(), T.getD());

	double volABMP = ABMP.volume();
	double volBCMP = BCMP.volume();
	double volABPD = ABPD.volume();
	double volCPBD = CPBD.volume();
	double volABCD = T.volume();
	double sum = volABMP + volBCMP + volABPD + volCPBD;

	if (volABCD < sum) return true;
	return false;
}

bool operator==(const Point& P, const Tetrahedron& T) // Point == Tetrahedron
{
	if (!(P > T) and !(P < T)) return true;
	return false;
}

std::ostream& Tetrahedron::ins(std::ostream& out)const {
	std::ofstream writer("tetrahedron.html");

	std::string html = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Document</title>
    <style>
        body{
  perspective:9000px;
  padding-top:10%;
}
.tetra{
  position:relative;
  width:20%; 
  padding-bottom:17.32%; /* height of equilateral triangle = sin60° * width */
  margin:0 auto;  
  transform-style:preserve-3d;  
  transform:rotatex(90deg) rotateY(0deg) rotatez(0deg);
  animation: rotate 10s linear infinite;
}

.tetra div{
  position:absolute;
  top:0;left:0;
  width:100%; height:100%;
  -webkit-clip-path:polygon(50% 0, 100% 100%, 0% 100%);
  clip-path:polygon(50% 0, 100% 100%, 0% 100%);
  background:teal;  
  transform-style:preserve-3d;
}

/* Rotation of –109.5° is angle(C, M[AB], D), per http://www.f-lohmueller.de/pov_tut/geo/geom_200e.htm, 180° – atan(2 * sqrt(2)) ≈ 109.5° */
.tetra .face2{
  transform-origin:0% 100%;
  transform:rotate(-60deg) rotatex(-109.5deg);
  background:gold;
}
.tetra .face3{
  transform-origin:100% 100%;
  transform:rotate(60deg) rotatex(-109.5deg);
  background:darkorange;
}
.tetra .face4{
  transform-origin:50% 100%;
  transform:rotate(180deg) rotatex(-109.5deg);
  background:pink;
}
@keyframes rotate{
  50%{transform:rotatex(100deg) rotateY(10deg) rotatez(180deg);}
  100%{transform:rotatex(90deg) rotateY(0deg) rotatez(360deg);}
}
    </style>
</head>
<body>
<h1>Tetrahedron</h1>
<h2>Coordinates:</h2>)";
html += "<p> A(";

// A coordinates
std::string tmpA;
tmpA = numberToChar(A.getX());
for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
html += ",";

tmpA = numberToChar(A.getY());
for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
html += ",";

tmpA = numberToChar(A.getZ());
for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
html += ") </p>\n";
html += "<p> B(";

// B coordinates
std::string tmpB;
tmpB = numberToChar(B.getX());
for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
html += ",";

tmpB = numberToChar(B.getY());
for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
html += ",";

tmpB = numberToChar(B.getZ());
for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
html += ") </p>\n";

html += "<p> C(";

// C coordinates
std::string tmpC;
tmpC = numberToChar(C.getX());
for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
html += ",";

tmpC = numberToChar(C.getY());
for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
html += ",";

tmpC = numberToChar(C.getZ());
for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
html += ") </p>\n";

// D coordinates
html += "<p> D(";
std::string tmpD;
tmpD = numberToChar(D.getX());
for (int i = 0; i < tmpD.length(); i++)html += tmpD[i];
html += ",";

tmpD = numberToChar(D.getY());
for (int i = 0; i < tmpD.length(); i++)html += tmpD[i];
html += ",";

tmpD = numberToChar(D.getZ());
for (int i = 0; i < tmpD.length(); i++)html += tmpD[i];
html += ") </p>\n";

html+=
    R"(<div class="tetra">
        <div class="face1"></div>
        <div class="face2"></div>
        <div class="face3"></div>
        <div class="face4"></div>
        
    </div>
</body>
</html>)";

	out << "Drawing tetrahedron\n";
	out << A << std::endl << B << std::endl << C << std::endl << D << std::endl;
	writer << html;
	writer.close();
	return out;
}


std::istream& Tetrahedron::ext(std::istream& in)
{
	std::cout << "Please enter the coordinates of the first point:\n";
	A.ext(in);
	std::cout << "Please enter the coordinates of the second point:\n";
	B.ext(in);
	std::cout << "Please enter the coordinates of the third point:\n";
	C.ext(in);
	std::cout << "Please enter the coordinates of the fourth point:\n";
	D.ext(in);
	return in;
}

