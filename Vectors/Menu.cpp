#include<iostream>
#include"Line.h"
#include"Point.h"
#include"Segment.h"
#include"Triangle.h"
#include"Vector.h"
#include"Menu.h"
using namespace std;


int printMenu() {

	cout << endl << "0 - Exit" << endl;
	cout << endl << "1 - Point" << endl;
	cout << endl << "2 - Vector" << endl;
	cout << endl << "3 - Line" << endl;
	cout << endl << "4 - Segment" << endl;
	cout << endl << "5 - Triangle" << endl;

	int option;


	while (true) {
		cout << "Please enter geometrical object: " << endl;
		cin >> option;
		if (option < 0 || option > 5) {
			cout << "Wrong! Please choose again: " << endl;
			cin >> option;
		}
		else if (option == 0) {
			cout << "Successfully exited the program! Have an amazing day :)";
			break;
		}
		else {
			switch (option)
			{
			case 1:
				printAllPointOperations();
				break;
			case 2:
				printAllVectorOperations();
				break;
			case 3:
				printAllLineOperations();
				break;
			case 4:
				printAllSegmentOperations();
				break;
			case 5:
				printAllTriangleOperations();
				break;
			}

		}


	}
	return 0;
}

int printAllPointOperations() {
	int chooseOperation;
	Point p;
	cin >> p;
	cout << "Please enter operation for the object: " << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Find in which quadrant the point is" << endl;
	cout << "2 - Find if two points are equal" << endl;
	while (true) {
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 2) {
			cout << "Wrong! Please choose again: " << endl;
			cin >> chooseOperation;
		}
		else if (chooseOperation == 0) {
			break;
		}
		else {
			switch (chooseOperation)
			{
			case 1:
				int quadrant;
				quadrant = p.quadrant();
				cout << "Point is in" << quadrant << endl;
				break;
			case 2:
				Point p2;
				cin >> p2;
				if (p == p2)
				{
					cout << "Points are equel!" << endl;
				}
				else {
					cout << "Points are not equel!" << endl;

				}
				break;
			}

		}
	}
	return 0;
}

int printAllVectorOperations() {
	int chooseOperation;
	Vector v;
	cin >> v;
	cout << "Please enter operation for the object: " << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - calculation of vector length" << endl;
	cout << "2 - calculate the direction of the vector" << endl;
	cout << "3 - check for zero vector" << endl;
	cout << "4 - check for parallelism of two vectors" << endl;
	cout << "5 - check for perpendicularity of two vectors" << endl;
	cout << "6 - addition of two vectors" << endl;
	cout << "7 - multiplication of a vector by a real number" << endl;
	cout << "8 - scalar product of two vectors" << endl;
	cout << "9 - vector product of two vectors" << endl;
	cout << "10 - cross product of three vectors" << endl;
	while (true) {
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 10) {
			cout << "Wrong! Please enter again: " << endl;
			cin >> chooseOperation;
		}
		else if (chooseOperation == 0) {
			break;
		}
		else {
			switch (chooseOperation)
			{
			case 1:
				double lenght;
				lenght = v.length();
				cout << "The vector lenght is: " << lenght << endl;
				break;
			case 2:
				cout << "Direction of vector is: " << endl << v.direction();
				break;
			case 3:
				if (v.isNull())
				{
					cout << "Vector is null" << endl;

				}
				else
				{
					cout << "Vector is not null" << endl;
				}
				break;
			case 4:
			{
				Vector v2;
				cin >> v2;
				if (v.parallel(v2)) {
					cout << "Vectors are parallel" << endl;
				}
				else {
					cout << "Vectors are not parallel" << endl;
				}
				break;
			}


			case 5:
			{
				Vector v2;
				cin >> v2;
				if (v.perpendicular(v2)) {
					cout << "Vectors are perpendicular" << endl;
				}
				else {
					cout << "Vectors are not perpendicular" << endl;
				}
				break;
			}

			case 6:
			{
				Vector v2;
				cin >> v2;
				Vector result = v + v2;
				cout << "The addition of the two vectors is: " << endl << result;
				break;
			}
			case 7:
			{
				double realNumber;
				cout << "Enter real number: ";
				cin >> realNumber;
				Vector result;
				result = v * realNumber;
				cout << "Result vector is: " << result;
				break;
			}


			case 8:
			{
				double result;
				Vector v2;
				cin >> v2;
				result = v * v2;
				cout << "Scalar product of the two vectors is:" << result;
				break;
			}
			case 9:
			{
				Vector v2;
				cin >> v2;
				Vector result = v ^ v2;
				cout << "Vector product of the two vectors is: " << endl << result;
				break;
			}

			case 10:
			{
				Vector v2;
				cin >> v2;
				Vector v3;
				cin >> v3;
				double result = v(v2, v3);
				cout << "Cross product ot the three vectors is: " << result;
				break;
			}

			}
		}
	}
	return 0;
}



int printAllLineOperations() {
	Line l;
	cin >> l;
	int chooseOperation;
	cout << "Please enter operation for the object: " << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Find line direction" << endl;
	cout << "2 - Find normal vector" << endl;
	cout << "3 - Find angle between two lines" << endl;
	cout << "4 - Find if a given point lies on a line" << endl;
	cout << "5 - Find if two lines are parallel" << endl;
	cout << "6 - Find if two lines coincide" << endl;
	cout << "7 - Find if two lines intersect" << endl;
	cout << "8 - Find if two lines are skew" << endl;
	cout << "9 - Find if two lines are perpendicular" << endl;
	cout << "10 - Draw line" << endl;
	while (true)
	{
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 10) {
			cout << "Wrong! Please enter again: " << endl;
			cin >> chooseOperation;
		}
		else if (chooseOperation == 0) {
			break;
		}
		else {
			switch (chooseOperation)
			{
			case 1:
			{
				Vector lineVector = l.lineDirection();
				cout << "Direction of the line is: " << endl << lineVector;

				break;
			}

			case 2:
			{
				Vector normalVector = l.lineDirection();
				cout << "Normal vector is: " << endl << normalVector;
				break;
			}
			case 3:

			{
				Line l2;
				cin >> l2;
				double result = l.findAngleOfBetweenTwoLines(l2);
				cout << "Angle between two lines is: " << result << endl;
				break;
			}
			case 4:
			{
				Point p;
				cin >> p;
				if (l + p) {
					cout << "Point lies on the line" << endl;
				}
				else
				{
					cout << "Point does not lie on the line" << endl;
				}
				break;
			}
			case 5:
			{
				Line l2;
				cin >> l2;
				if (l || l2) {
					cout << "The two lines are parallel" << endl;

				}
				else
				{
					cout << "The two lines are not parallel" << endl;

				}
				break;
			}
			case 6:
			{
				Line l2;
				cin >> l2;
				if (l == l2) {
					cout << "The two lines coincide" << endl;

				}
				else
				{
					cout << "The two lines do not coincide" << endl;
				}
				break;
			}
			case 7:
			{
				Line l2;
				cin >> l2;
				if (l && l2) {
					cout << "The two lines intersect" << endl;

				}
				else
				{
					cout << "The two lines do not intersect" << endl;
				}
				break;
			}
			case 8:
			{
				Line l2;
				cin >> l2;
				if (l != l2) {
					cout << "The two lines are skew" << endl;

				}
				else
				{
					cout << "The two lines are not skew" << endl;
				}
				break;
			}
			case 9:
			{
				Line l2;
				cin >> l2;
				if (l | l2) {
					cout << "The two lines are perpendicular" << endl;

				}
				else
				{
					cout << "The two lines are not perpendicular" << endl;
				}

				break;
			}
			case 10:
				cout << l;
				break;
			}
		}
	}
	return 0;
}


int printAllSegmentOperations() {
	int chooseOperation;
	Segment s;
	cin >> s;
	cout << "Please enter operation for the object: " << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Find length of segment" << endl;
	cout << "2 - Find center of segment" << endl;
	while (true)
	{
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 2) {
			cout << "Wrong! Please choose again: " << endl;
			cin >> chooseOperation;
		}
		else if (chooseOperation == 0) {
			break;
		}
		else {
			switch (chooseOperation)
			{
			case 1:
				double lenght;
				lenght = s.length();
				cout << "Lenght of segment is: " << lenght << endl;
				break;
			case 2:
				Point result = s.middle();
				cout << result << endl;
				break;
			}
		}
		return 0;

	}
}



int printAllTriangleOperations() {
	Triangle t;
	cin >> t;
	int chooseOperation;
	cout << "Please enter operation for the object: " << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Find type of triangle" << endl;
	cout << "2 - Find area of triangle" << endl;
	cout << "3 - Find perimeter of triangle" << endl;
	cout << "4 - Find medicenter of triangle" << endl;
	cout << "5 - Find if a point lies on the same plane as the triangle's and if it is inside him" << endl;
	cout << "6 - Find if a point lies on the same plane as the triangle's and if it is outside of him" << endl;
	cout << "7 - Find if a point lies on a given line of the triangle's" << endl;
	cout << "8 - Draw triangle" << endl;

	while (true)
	{
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 8)
		{
			cout << "Wrong! Please enter again: " << endl;
			cin >> chooseOperation;
		}
		else if (chooseOperation == 0) {
			break;
		}
		else
		{
			switch (chooseOperation)
			{
			case 1:
				cout << "Type of triangle is: " << t.type() << endl;
				break;
			case 2:
				cout << "Area of triangle is: " << t.area() << endl;
				break;
			case 3:
				cout << "Perimeter of triangle is: " << t.perimeter() << endl;
				break;
			case 4:
				cout << "Medicenter of triangle is: " << t.medicenter() << endl;
				break;
			case 5:
			{
				Point p;
				cin >> p;
				if (t < p) {
					cout << "Point lies on the same plane as the triangle and it is inside him" << endl;
				}
				else {
					cout << "Point does not lie on the same plane as the triangle and it is inside him" << endl;
				}
				break;
			}
			case 6:
			{
				Point p;
				cin >> p;
				if (t > p) {
					cout << "Point lies on the same plane as the triangle and it is outside him" << endl;
				}
				else {
					cout << "Point does not lie on the same plane as the triangle and it is outside him" << endl;
				}
				break;
			}

			case 7:
			{
				Point p;
				cin >> p;
				if (t == p) {
					cout << "Point lies on at least on one side of the triangle" << endl;
				}
				else {
					cout << "Point does not lie on neither of the triangle's sides" << endl;
				}
				break;
			}
			case 8:
				cout << t;

				break;



			}

		}
	}

	return 0;
}