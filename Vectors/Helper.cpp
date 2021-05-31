#include"Helper.h"


std::string numberToChar(double num)// if coordinates of Point are bigger than one digit number
{
    double tmp = num;
    std::string result = std::to_string(tmp);
    return result;
}

double findAngle(double x1, double x2, double x3, double y1, double y2, double y3, double z1, double z2, double z3)
{
    double num = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) + (z2 - z1) * (z3 - z1);

    double den = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2)) * \
        sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2) + pow((z3 - z1), 2));

    double angle = acos(num / den) * (180.0 / 3.141592653589793238463);
    return angle;
}
