#ifndef Test_Triangle_hh
#define Test_Triangle_hh
#include "Point.h"
#include "Triangle.h"
class Test_Triangle {
private:
	template<typename T>
	bool assert_equal(T expectedResult, T actualResult) const {
		return expectedResult == actualResult;
	}

public:
	/*
	void assert_type()const {
		Point A = Point(6, 7, 1);
		Point B = Point(8, 9, 12);
		Point C = Point(13, 9, 8);
		Triangle test_triangle = Triangle(A, B, C);

		char* expectedType = new char[] {"Sharp-angled"};
		char* actualType = test_triangle.type();

		bool isValid = true;
		for (int i = 0; i < strlen(expectedType); i++)
		{
			if (expectedType[i] != actualType[i])
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
		{
			std::cout << "Type function is correct ! " << std::endl;
			std::cout << "---------------------------------------" << std::endl;
		}
		else {
			std::cout << "Type function is not correct ! " << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
		if (expectedType != nullptr)
		{
			delete[]expectedType;
			expectedType = nullptr;
		}

	}
	*/
	void assert_area()const {

		Point A = Point(6, 7, 1);
		Point B = Point(8, 9, 12);
		Point C = Point(13, 9, 8);
		Triangle test_triangle = Triangle(A, B, C);

		int expectedResult = abs(32.144);
		int actualResult = abs(test_triangle.area());
		bool isValid = assert_equal(expectedResult, actualResult);

		if (isValid)
		{
			std::cout << "Area function is correct ! " << std::endl;
			std::cout << "---------------------------------------" << std::endl;
		}
		else {
			std::cout << "Area function is not correct ! " << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}

	}
	void assert_perimeter() const {
		Point A = Point(2.22, 5.37, 7.27);
		Point B = Point(3.63, 6.21, 8.19);
		Point C = Point(4.17, 2.35, 1);

		Triangle test_triangle = Triangle(A, B, C);

		int expectedResult = abs(17.2874);
		int actualResult = abs(test_triangle.perimeter());

		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Perimeter function is correct ! " << std::endl;
			std::cout << "---------------------------------------" << std::endl;
		}
		else {
			std::cout << "Perimeter function is not correct ! " << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
	}
	void assert_medicenter()const {
		Point A = Point(1, -1, 3);
		Point B = Point(-2, 0, 4);
		Point C = Point(4, 1, -1);

		Triangle test_triangle = Triangle(A, B, C);

		Point expectedMedicenter = Point(1, 0, 2);
		Point actualMedicenter = test_triangle.medicenter();
		bool isValid = assert_equal(expectedMedicenter, actualMedicenter);
		if (isValid)
		{
			std::cout << "Medicenter function is correct ! " << std::endl;
			std::cout << "---------------------------------------" << std::endl;
		}
		else {
			std::cout << "Medicenter function is not correct ! " << std::endl;
			std::cout << "-----------------------------------------" << std::endl;
		}
	}

	//TO DO: Implement operator < > == 

};
#endif // !Test_Triangle_hh
