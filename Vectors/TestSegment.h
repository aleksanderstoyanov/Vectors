#ifndef TESTSEGMENT_H
#define TESTSEGMENT_H
#include<iostream>
#include "Line.h"
#include "Segment.h"

class Test_Segment
{
private:
	template<typename T>
	bool assert_equal(T expectedResult, T actualResult) const
	{
		return expectedResult == actualResult;
	}
public:
	int assert_segment_length() const
	{
		double expectedLength = 5;
		Point A = Point(-1, 3, 2);
		Point B = Point(2, -1, 2);
		Segment test_segment(A, B);
		double actualLength = test_segment.length();
		bool isValid = assert_equal(expectedLength, actualLength);
		if (isValid)
		{
			std::cout << "Segment length function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Segment length function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}

	int assert_segment_middle() const
	{
		Point A(3, 2, 1);
		Point B(7, 2, 13);
		Point expectedResult(5, 2, 7);
		Segment test_segment(A, B);
		Point actualResult = test_segment.middle();
		bool isValid = assert_equal(expectedResult, actualResult);
		if (isValid)
		{
			std::cout << "Segment finding middle function is correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		else {
			std::cout << "Segment finding middle function is not correct" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}
		return 0;
	}
};
#endif
