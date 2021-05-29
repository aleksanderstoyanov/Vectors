#ifndef TESTTETRAHEDRON_H
#define TESTTETRAHEDRON_H
#include"Tetrahedron.h"

class Test_Tetrahedron
{
private:
	template<typename T>
	bool assert_equal(T expectedResult, T actualResult) const
	{
		return expectedResult == actualResult;
	}
public:

	int assert_tetrahedron_isRegular() const
	{
		bool expectedResult = true;
		Point A(1, 1, 1);
		Point B(-1, -1, 1);
		Point C(1, -1, -1);
		Point D(-1, 1, -1);
		Tetrahedron test(A, B, C, D);
		bool actualResult = test.isRegular();
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Tetrahedron isRegular function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Tetrahedron isRegular function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}

	int assert_tetrahedron_isOrthocentric() const
	{
		bool expectedResult = true;
		Point A(1, 1, 1);
		Point B(-1, -1, 1);
		Point C(1, -1, -1);
		Point D(-1, 1, -1);  // this is an example of a regular and an orthocentric tetrahedron
		Tetrahedron test(A, B, C, D);
		bool actualResult = test.isOrthocentric();
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Tetrahedron isOrthocentric function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Tetrahedron isOrthocentric function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}

	int assert_tetrahedron_surfaceArea() const
	{
		double expectedArea = 8.4642849919461938;
		Point A(1, 2, 0);
		Point B(0, 1, -1);
		Point C(1, 0, 1);
		Point D(-1, 0, 1);
		Tetrahedron test(A, B, C, D);
		double actualArea = test.surfaceArea();
		bool isValid = assert_equal(expectedArea, actualArea);
		if (isValid)
		{
			std::cout << "Tetrahedron surfaceArea function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Tetrahedron surfaceArea function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}

	int assert_tetrahedron_volume() const
	{
		double expectedVolume = 10.;
		Point A(0, 0, 0);
		Point B(3, 0, 0);
		Point C(0, 4, 0);
		Point D(0, 0, 5);
		Tetrahedron test(A, B, C, D);
		double actualVolume = test.volume();
		bool isValid = assert_equal(expectedVolume, actualVolume);
		if (isValid)
		{
			std::cout << "Tetrahedron volume function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Tetrahedron volume function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}

};

#endif


