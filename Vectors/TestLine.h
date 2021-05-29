#ifndef Test_Line_hh
#define Test_Line_hh
#include<iostream>
#include "Vector.h"
#include "Line.h"
class Test_Line {
private:
	template<typename T>
	bool assert_equal(T expectedResult, T actualResult) const {
		return expectedResult == actualResult;
	}
public:

	void assert_lineDirection() const {
		Vector expectedVector = Vector(2, 0, -2);

		Point p = Point(1, 2, 3);
		Point p2 = Point(3, 2, 1);
		Line test_line = Line(p, p2);
		Vector actualVector = Vector(test_line.getX(), test_line.getY(), test_line.getZ());
		bool isValid = assert_equal(expectedVector, actualVector);
		if (isValid)
		{
			std::cout << "Vector direction function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Vector direction function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}

	void assert_normalVector() const {
		Vector expectedNormalVector = Vector(0, -2, 4);

		Point p = Point();
		Vector v = Vector(5, 4, 2);
		Line test_line = Line(p, v);
		Vector actualNormalVector = test_line.findNormalVector();
		bool isValid = assert_equal(expectedNormalVector, actualNormalVector);
		if (isValid)
		{
			std::cout << "Normal vector function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Normal vector function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}
	void assert_parallelOperator() const {

		bool expectedResult = false;
		Point p1 = Point(3, 4, 1);
		Vector v1 = Vector(2, -1, 3);
		Line line_test1 = Line(p1, v1);

		Point p2 = Point(1, 3, 4);
		Vector v2 = Vector(4, -2, 5);
		Line line_test2 = Line(p2, v2);

		bool actualResult = line_test1 || line_test2;
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Parallel operator is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Parallel operator is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}
	void assert_doubleEqualOperator()const {
		bool expectedResult = true;
		Point p1 = Point(-1, 0, 4);
		Vector v1 = Vector(-1, 2, 5);
		Line line_test1 = Line(p1, v1);

		Point p2 = Point(4, -10, -21);
		Vector v2 = Vector(-2, 4, 10);
		Line line_test2 = Line(p2, v2);

		bool actualResult = line_test1 == line_test2;
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Double equal operator is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Double equal operator is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}
	void assert_intersectOperator()const {
		bool expectedResult = false;

		Point p1 = Point(3, 4, 1);
		Vector v1 = Vector(2, -1, 3);
		Line line_test1 = Line(p1, v1);

		Point p2 = Point(1, 3, 4);
		Vector v2 = Vector(4, -2, 5);
		Line line_test2 = Line(p2, v2);

		bool actualResult = line_test1 && line_test2;
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Intersect operator is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Intersect operator is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
	}
	void assert_skewOperator()const {
		bool expectedResult = true;
		Point p1 = Point(3, 4, 1);
		Vector v1 = Vector(2, -1, 3);
		Line line_test1 = Line(p1, v1);

		Point p2 = Point(1, 3, 4);
		Vector v2 = Vector(4, -2, 5);
		Line line_test2 = Line(p2, v2);

		bool actualResult = line_test1 != line_test2;
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Skew operator is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Skew operator is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}

	}

};
#endif // !Test_Line_hh

