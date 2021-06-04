#include"Segment.h"

//BIG FIVE
Segment::Segment()
	:Line(), S(Point()), E(Point()), beg(0.), end(0.)
{}

Segment::Segment(Point A, Point B)
	: Line(A, B), S(A), E(B)     /* this should do
								x =  (Xb - Xa) = b1;
								y =  (Yb - Ya) = b2;
								z =  (Zb - Za) = b3;
								*/
{

	beg = (A.getX() - A.getX()) / getX(); // substitute with Point A -> t = (x - a1)/b1;
	end = (B.getX() - A.getX()) / getX(); //substitute with Point B -> t = (x - a1)/b1;
}

Segment::Segment(const Segment& rhs)
	: Line(rhs), beg(rhs.beg), end(rhs.end), S(rhs.S), E(rhs.E) {}

Segment& Segment::operator=(const Segment& rhs)
{
	if (this != &rhs)
	{
		Line::operator=(rhs);
		beg = rhs.beg;
		end = rhs.end;
		S = rhs.S;
		E = rhs.E;
	}
	return *this;
}

Segment::~Segment()
{
	/*
	Line::~Line();
	std::cout << "Segment destructor" << std::endl;
	*/
}

// inserter
std::ostream& Segment::ins(std::ostream& out) const
{
	out << "Starting Point: (" << S.getX() << ", " << S.getY() << ", " << S.getZ() << ")" << std::endl;
	S.ins(out);
	out << "Ending Point: (" << E.getX() << ", " << E.getY() << ", " << E.getZ() << ")" << std::endl;
	E.ins(out);
	/*out << "Parametric equation: " << std::endl;
	out << "S: " << "x = " << S.getX() << " + " << E.getX() - S.getX()  << "t" << ", y = " << S.getY() << " + " << E.getY() - S.getY() << "t" << ", z = " << S.getZ() << " + " << E.getZ() - S.getZ() << "t" << std::endl;
	*/
	std::cout << "Components of the line on which segment lies:\n";
	std::cout << "------------------------\n";
	Line::ins(out);
	std::cout << "------------------------\n";
	out << "is defined Segment for t in interval [ " << beg << ", " << end << " ]" << std::endl;

	std::ofstream writer("segment.html");
	std::string html = R"(<!DOCTYPE html>
        <html lang="en">

        <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
        <style>

#line{
    position: relative;
    border: none;
    height: 5px;
    background: black;
        margin-bottom: 44px;
    width: 360px;
        margin-top: -48px;

    }
    #p1{
       font-size: 30px;
margin-left: 567px;
    }
        #p2{
           font-size: 30px;
   margin-left: 937px;
   margin-top: -75px;
    }

        #coordinates-p{
   margin-top: -30px;
            margin-left: 520px;
    }
        #coordinates-p2{
            margin-left: 940px;
            margin-top: -33px;
    }
        </style>
        </head>
        <body>
        <p id="p1">&#9900</p>
        <div>
        <hr id="line">
        <p id="coordinates-p">)"; /*S(2, 5, 6) < / p >*/
	html += "S(";
	std::string tmpS;
	tmpS = numberToChar(S.getX());
	for (int i = 0; i < tmpS.length(); i++)html += tmpS[i];
	html += ",";

	tmpS = numberToChar(S.getY());
	for (int i = 0; i < tmpS.length(); i++)html += tmpS[i];
	html += ",";

	tmpS = numberToChar(S.getZ());
	for (int i = 0; i < tmpS.length(); i++)html += tmpS[i];
	html += ") </p>\n";


	html += R"(<p id="coordinates-p2">)";
	html += "E(";
	std::string tmpE;
	tmpE = numberToChar(E.getX());
	for (int i = 0; i < tmpE.length(); i++)html += tmpE[i];
	html += ", ";
	
	tmpE = numberToChar(E.getY());
	for (int i = 0; i < tmpE.length(); i++)html += tmpE[i];
	html += ", ";
	
	tmpE = numberToChar(E.getZ());
	for (int i = 0; i < tmpE.length(); i++)html += tmpE[i];
	html += ")</p>\n";
	html += R"(
        <p id="p2">&#9900</p>
        </div>
        </body>
        </html>)";
	writer << html;
	writer.close();
	return out;
}

// functions
double Segment::length() const  // make the segment a vector and then find its length
{
	//Point S(A.getX() + (B.getX() - A.getX()) * beg, A.getY() + (B.getY() - A.getY()) * beg, A.getZ() + (B.getZ() - A.getZ()) * beg);
	//Point E(A.getX() + (B.getX() - A.getX()) * end, A.getY() + (B.getY() - A.getY()) * end, A.getZ() + (B.getZ() - A.getZ()) * end);
	Vector V(S, E);
	return V.Vector::length();
}

Point Segment::middle() const
{
	//((xA + xB)/2,(yA + yB)/2,(zA + zB)/2)
	return Point((S.getX() + E.getX()) / 2, (S.getY() + E.getY()) / 2, (S.getZ() + E.getZ()) / 2);
}

bool operator==(const Point& lhs, const Segment& rhs)    // first make Vector(S,lhs); and find its length1
{                                                         // then make Vector(lhs,E); and find its length2
														 //  if (length1 + length2) = Segment.length() -> true
	Vector first(rhs.getS(), lhs);
	Vector second(lhs, rhs.getE());
	if ((first.length() + second.length()) == rhs.length()) return true;
	return false;
}

std::istream& Segment::ext(std::istream& in)
{
	S.ext(in);
	E.ext(in);
	return in;
}
