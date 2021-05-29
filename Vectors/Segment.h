#ifndef SEGMENT_H
#define SEGMENT_H
#include"Line.h"
//#include<cmath>

///             First case: when we save in x  y  z the incline b(of the Line) 

/*
    param Equations:             In x  y  z we save the incline b                    Point A(Xa,Ya,Za);
                                 =>Inherited from Line(A,b);                         Point B(Xb,Yb,Zb);  {Segment}
    x = a1 + b1*t;               => x = b1;
    y = a2 + b2*t;                  y = b2; and point A {this is Line}
    z = a3 + b3*t;                  z = b3;

    => to find the range of t
       => first: find begin -> substitute with Point A -> t = (x - a1)/b1;
                                                         beg = t = (b1 - Xa) / b1;

    =>
       => second: find end -> substitute with Point B -> t = (x - a1)/b1;
                                                         end =  t = (b1 - Xb) / b1;

*/

class Segment : public Line
{
public:
    //BIG FIVE
    Segment();
    Segment(Point, Point);
    Segment(const Segment&);
    Segment& operator=(const Segment&);
    virtual ~Segment();

    // inserter
    virtual std::ostream& ins(std::ostream&) const;

    // functions
    double length() const;
    Point middle() const;

    //inline geters
    double getBeg() const { return beg; };
    double getEnd() const { return end; };
    Point getS() const { return S; };
    Point getE() const { return E; };



private:
    double beg; // for what t the param equation is equal to the coordinate of the starting Point
    double end; // --- of the ending Point
    Point S;  // starting point
    Point E;  // ending point
};

bool operator==(const Point&, const Segment&); // Point -> lhs

#endif

