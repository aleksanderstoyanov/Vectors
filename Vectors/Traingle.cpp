#include "Triangle.h"



Triangle::Triangle() : a(Point()), b(Point()), c(Point()) {

}
Triangle::Triangle(const Point& inputA, const Point& inputB, const Point& inputC) : a(inputA), b(inputB), c(inputC) {

}
Triangle::Triangle(const Triangle& copy) : a(copy.a), b(copy.b), c(copy.c) {

}
Triangle::~Triangle() {
    //Calling destructor of triangle;
}
Triangle& Triangle::operator=(const Triangle& rhs) {

    if (this != &rhs)
    {
        this->a = rhs.a;
        this->b = rhs.b;
        this->c = rhs.c;
    }

    return *this;
}

Point Triangle::getA() const { return a; }

Point Triangle::getB() const { return b; }

Point Triangle::getC() const { return c; }

std::ostream& Triangle::ins(std::ostream& out)const
{
    out << "Triangle points:" << std::endl;
    out << "A" << " (" << a.getX() << ", " << a.getY() << ", " << a.getZ() << ")" << std::endl;
    out << "B" << " (" << b.getX() << ", " << b.getY() << ", " << b.getZ() << ")" << std::endl;
    out << "C" << " (" << c.getX() << ", " << c.getY() << ", " << c.getZ() << ")" << std::endl;


    // ------------- Graphical representation of a Triangle -----------------

    std::ofstream writer("triangle.html");

    std::string html = R"(<!DOCTYPE html>
        <html>
        <head>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
        .triangle-right{
            width: 0;
            height: 0;
            border-top: 25px solid transparent;
            border-left: 50px solid #555;
            border-bottom: 25px solid transparent;
    }
        #B{
            margin-left: 17px;
            margin-top: -7px;
    }
        </style>
        </head>
        <body>
 
        <h2>Triangle</h2>
        )";
    html += "<p> C(";

    // C'coordinates
    std::string tmpC;
    tmpC = numberToChar(c.getX());
    for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
    html += ",";

    tmpC = numberToChar(c.getY());
    for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
    html += ",";

    tmpC = numberToChar(c.getZ());
    for (int i = 0; i < tmpC.length(); i++)html += tmpC[i];
    html += ") </p>\n";
    html += R"(
        <div class="triangle-right">
)";
    html += "<p> B(";

    //  B'coordinates 
    std::string tmpB;
    tmpB = numberToChar(b.getX());
    for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
    html += ",";

    tmpB = numberToChar(b.getY());
    for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
    html += ",";

    tmpB = numberToChar(b.getZ());
    for (int i = 0; i < tmpB.length(); i++)html += tmpB[i];
    html += ") </p>\n";
    html += R"(
        </div>)";
    html += "<p> A(";

    // A'coordinates
    std::string tmpA;
    tmpA = numberToChar(a.getX());
    for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
    html += ",";

    tmpA = numberToChar(a.getY());
    for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
    html += ",";

    tmpA = numberToChar(a.getZ());
    for (int i = 0; i < tmpA.length(); i++)html += tmpA[i];
    html += ") </p>\n";
    html += R"(
        </body>
        </html>)";

    writer << html;
    writer.close();

    return out;
}

std::ostream& operator<<(std::ostream& lhs, const Triangle& rhs) {
    return rhs.ins(lhs);
}

int Triangle::type() const  // равнобедрен/равностранен/остроъгълен/правоъгълен/тъпоъгълен)
                              // isosceles, equilateral, sharp-angled(acute), right-angled, obtuse
{
    // check which point is equal
    if (a == b or a == c)
    {
        throw EqualPointException(a.getX(), a.getY(), a.getZ());
    }
    else if (b == c)
    {
        throw EqualPointException(b.getX(), b.getY(), b.getZ());
    }

    double alpha, betha, gamma;
    alpha = findAngle(a.getX(), b.getX(), c.getX(), a.getY(), b.getY(), c.getY(), a.getZ(), b.getZ(), c.getZ());
    betha = findAngle(b.getX(), c.getX(), a.getX(), b.getY(), c.getY(), a.getY(), b.getZ(), c.getZ(), a.getZ());
    gamma = findAngle(c.getX(), b.getX(), a.getX(), c.getY(), b.getY(), a.getY(), c.getZ(), b.getZ(), a.getZ());

    std::cout << "\nTiangle's angles are:\n";
    std::cout << "Angle alpha = " << alpha << " degrees" << std::endl;
    std::cout << "Angle betha = " << betha << " degrees" << std::endl;
    std::cout << "Angle gamma = " << gamma << " degrees" << std::endl;

    if ((alpha == betha) or (alpha == gamma) or (betha == gamma))
    {
        std::cout << "\nType of Triangle is isosceles\n";
        return 0;
    }
    else if (alpha == betha == gamma)
    {
        std::cout << "\nType of Triangle is equilateral\n";
        return 0;
    }
    else if (alpha < 90 and betha < 90 and gamma < 90)
    {
        std::cout << "\nType of Triangle is sharp-angled\n";
        return 0;
    }
    else if (alpha == 90 or betha == 90 or gamma == 90)
    {
        std::cout << "\nType of Triangle is right-angled\n";
        return 0;
    }
    else if (alpha > 90 or betha > 90 or gamma > 90)
    {
        std::cout << "\nType of Triangle is obtuse\n";
        return 0;
    }
    
}

double Triangle::area()const
{
    Vector AB(a, b);
    Vector AC(a, c);
    Vector Area(AB ^ AC);
    return (Area.length() / 2.);
}
double Triangle::perimeter() const {
    const Vector AB = Vector(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ());
    const Vector BC = Vector(c.getX() - b.getX(), c.getY() - b.getY(), c.getZ() - b.getZ());
    const Vector AC = Vector(c.getX() - a.getX(), c.getY() - a.getY(), c.getZ() - a.getZ());

    double perimeter = AB.length() + BC.length() + AC.length();

    return perimeter;
}
Point Triangle::medicenter()const {
    double x, y, z;
    x = (a.getX() + b.getX() + c.getX()) / 3;
    y = (a.getY() + b.getY() + c.getY()) / 3;
    z = (a.getZ() + b.getZ() + c.getZ()) / 3;

    return Point(x, y, z);

}
bool Triangle::operator >(const Point& p)const  // throws exception !!

                                                    // Triangle > Point
                                                    /// Point is inside
{
    // first check whether the Point p is in the same plane with the points a,b,c (coplanar points)
    Vector AB(a, b);
    Vector AC(a, c);
    Vector AP(a, p);
    if (AB(AC, AP) != 0) // triple product
    {
        std::cout << "The given Point is not coplanar with the points of the triangle!\n";
        throw 1; // for now, later throw some exception !
    }

    Triangle ABP(a, b, p);   // divide Triangle in 3 smaller triangles
    Triangle BPC(b, c, p);
    Triangle CPA(a, b, p);
    double area_ABC = area();    // find areas of all of them
    double area_ABP = ABP.area();
    double area_BPC = BPC.area();
    double area_CPA = CPA.area();

    // check if one of the areas of the small triangles is 0 -> this means that the points of this triangle are collinear ->
                                                                                                     // lie on one line
    // make this area bigger for not to be in the case where Point p is inside 
    if (area_ABP == 0.) area_ABP++;
    else if (area_BPC == 0.) area_BPC++;
    else if (area_CPA == 0.) area_CPA++;

    if (area_ABC == (area_ABP + area_BPC + area_CPA)) return true;
    return false;
}

bool Triangle::operator <(const Point& p)const // throws exception !!

                                                    // Triangle < Point
                                                    /// Point is outside
{
    /// return !(this < p);  <- not doing this, because this way we will include the case when Point p lies on the triangle ==
     // first check whether the Point p is in the same plane with the points a,b,c (coplanar points)
    Vector AB(a, b);
    Vector AC(a, c);
    Vector AP(a, p);
    if (AB(AC, AP) != 0) // triple product
    {
        std::cout << "The given Point is not coplanar with the points of the triangle!\n";
        throw 2; // for now, later throw some exception !
    }

    Triangle ABP(a, b, p);   // divide Triangle in 3 smaller triangles
    Triangle BPC(b, c, p);
    Triangle CPA(a, b, p);
    double area_ABC = area();    // find areas of all of them
    double area_ABP = ABP.area();
    double area_BPC = BPC.area();
    double area_CPA = CPA.area();
    if (area_ABC < (area_ABP + area_BPC + area_CPA)) return true; // if Sabc < these 3 parts(Sabp + Sbpc + Scpa), then P is outside
    return false;
}

bool Triangle::operator ==(const Point& p)const // throws exception !!
{
    // first check whether the Point p is in the same plane with the points a,b,c (coplanar points)
    Vector AB(a, b);
    Vector AC(a, c);
    Vector AP(a, p);
    if (AB(AC, AP) != 0) // triple product
    {
        std::cout << "The given Point is not coplanar with the points of the triangle!\n";
        throw 3; // for now, later throw some exception !
    }

    Triangle ABP(a, b, p);   // divide Triangle in 3 smaller triangles
    Triangle BPC(b, c, p);
    Triangle CPA(a, b, p);
    double area_ABC = area();    // find areas of all of them
    double area_ABP = ABP.area();
    double area_BPC = BPC.area();
    double area_CPA = CPA.area();

    // check if one of the areas of the small triangles is 0 -> this means that the points of this triangle are collinear ->
                                                                          // lie on one line -> so Point lie on the Triangle
    if (area_ABP == 0. or area_BPC == 0. or area_CPA == 0.) return true;
    return false;
}

bool operator <(const Point& p, const Triangle& T)  // Point < Triangle
                                                    /// Point is inside
{
    // first check whether the Point p is in the same plane with the points a,b,c (coplanar points)
    Vector AB(T.getA(), T.getB());
    Vector AC(T.getA(), T.getC());
    Vector AP(T.getA(), p);
    if (AB(AC, AP) != 0) // triple product
    {
        std::cout << "The given Point is not coplanar with the points of the triangle!\n";
        throw 1; // for now, later throw some exception !
    }

    Triangle ABP(T.getA(), T.getB(), p);   // divide Triangle in 3 smaller triangles
    Triangle BPC(T.getB(), T.getC(), p);
    Triangle CPA(T.getA(), T.getB(), p);
    double area_ABC = T.area();    // find areas of all of them
    double area_ABP = ABP.area();
    double area_BPC = BPC.area();
    double area_CPA = CPA.area();

    // check if one of the areas of the small triangles is 0 -> this means that the points of this triangle are collinear ->
                                                                                                     // lie on one line
    // make this area twice bigger for not to be in the case where Point p is inside 
    if (area_ABP == 0.) area_ABP++;
    else if (area_BPC == 0.) area_BPC++;
    else if (area_CPA == 0.) area_CPA++;

    if (area_ABC == (area_ABP + area_BPC + area_CPA)) return true;
    return false;
}

bool operator >(const Point& p, const Triangle& T)  // Point > Triangle
                                                    /// Point is outside
{
    // first check whether the Point p is in the same plane with the points a,b,c (coplanar points)
    Vector AB(T.getA(), T.getB());
    Vector AC(T.getA(), T.getC());
    Vector AP(T.getA(), p);
    if (AB(AC, AP) != 0) // triple product
    {
        std::cout << "The given Point is not coplanar with the points of the triangle!\n";
        throw 1; // for now, later throw some exception !
    }

    Triangle ABP(T.getA(), T.getB(), p);   // divide Triangle in 3 smaller triangles
    Triangle BPC(T.getB(), T.getC(), p);
    Triangle CPA(T.getA(), T.getB(), p);
    double area_ABC = T.area();    // find areas of all of them
    double area_ABP = ABP.area();
    double area_BPC = BPC.area();
    double area_CPA = CPA.area();

    // check if one of the areas of the small triangles is 0 -> this means that the points of this triangle are collinear ->
                                                                                                     // lie on one line
    // make this area bigger for not to be in the case where Point p is inside 
    if (area_ABP == 0.) area_ABP++;
    else if (area_BPC == 0.) area_BPC++;
    else if (area_CPA == 0.) area_CPA++;

    if (area_ABC < (area_ABP + area_BPC + area_CPA)) return true;
    return false;
}

bool operator ==(const Point& P, const Triangle& T)
{
    if (!(P < T) and !(P > T)) return true;
    return false;
}

std::istream& Triangle::ext(std::istream& in) {
    std::cout << "Enter coordinates for point A" << std::endl;
    a.ext(in);
    std::cout << "Enter coordinates for point B" << std::endl;
    b.ext(in);
    std::cout << "Enter coordinates for point C" << std::endl;
    c.ext(in);
    return in;
}
std::istream& operator >>(std::istream& lhs, Triangle& rhs) {
    return rhs.ext(lhs);
}
