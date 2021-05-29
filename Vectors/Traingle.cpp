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

char* Triangle::numberToChar(double num) const // if coordinates of Point are bigger than one digit number
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
    char* tmpC;
    tmpC = numberToChar(c.getX());
    for (int i = 0; i < strlen(tmpC); i++)html += tmpC[i];
    html += ",";

    tmpC = numberToChar(c.getY());
    for (int i = 0; i < strlen(tmpC); i++)html += tmpC[i];
    html += ",";

    tmpC = numberToChar(c.getZ());
    for (int i = 0; i < strlen(tmpC); i++)html += tmpC[i];
    html += ") </p>\n";
    html += R"(
        <div class="triangle-right">
)";
    html += "<p> B(";

    //  B'coordinates 
    char* tmpB;
    tmpB = numberToChar(b.getX());
    for (int i = 0; i < strlen(tmpB); i++)html += tmpB[i];
    html += ",";

    tmpB = numberToChar(b.getY());
    for (int i = 0; i < strlen(tmpB); i++)html += tmpB[i];
    html += ",";

    tmpB = numberToChar(b.getZ());
    for (int i = 0; i < strlen(tmpB); i++)html += tmpB[i];
    html += ") </p>\n";
    html += R"(
        </div>)";
    html += "<p> A(";

    // A'coordinates
    char* tmpA;
    tmpA = numberToChar(a.getX());
    for (int i = 0; i < strlen(tmpA); i++)html += tmpA[i];
    html += ",";

    tmpA = numberToChar(a.getY());
    for (int i = 0; i < strlen(tmpA); i++)html += tmpA[i];
    html += ",";

    tmpA = numberToChar(a.getZ());
    for (int i = 0; i < strlen(tmpA); i++)html += tmpA[i];
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
double findAngle(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3)
{
    double num = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) + (z2 - z1) * (z3 - z1);

    double den = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2)) * \
        sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2) + pow((z3 - z1), 2));

    double angle = acos(num / den) * (180.0 / 3.141592653589793238463);
    return angle;
}


char* Triangle::type() const  // равнобедрен/равностранен/остроъгълен/правоъгълен/тъпоъгълен)
                              // isosceles, equilateral, sharp-angled(acute), right-angled, obtuse
{
    double alpha, betha, gamma;
    char i[] = "Isosceles";
    char e[] = "Equilateral";
    char s[] = "Sharp-angled";
    char r[] = "Right-angled";
    char o[] = "Obtuse";
    char error[] = "Invalid Triangle!";

    alpha = findAngle(a.getX(), b.getX(), c.getX(), a.getY(), b.getY(), c.getY(), a.getZ(), b.getZ(), c.getZ());
    betha = findAngle(b.getX(), c.getX(), a.getX(), b.getY(), c.getY(), a.getY(), b.getZ(), c.getZ(), a.getZ());
    gamma = findAngle(c.getX(), b.getX(), a.getX(), c.getY(), b.getY(), a.getY(), c.getZ(), b.getZ(), a.getZ());

    if ((alpha == betha) or (alpha == gamma) or (betha == gamma)) return i;
    else if (alpha == betha == gamma) return e;
    else if (alpha < 90 and betha < 90 and gamma < 90) return s;
    else if (alpha == 90 or betha == 90 or gamma == 90) return r;
    else if (alpha > 90 or betha > 90 or gamma > 90) return o;
    // check which point is equal
    else if (a == b or a == c)
    {
        throw EqualPointException(a.getX(), a.getY(), a.getZ());
    }
    else if (b == c)
    {
        throw EqualPointException(b.getX(), b.getY(), b.getZ());
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
    // make this area twice bigger for not to be in the case where Point p is inside 
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
