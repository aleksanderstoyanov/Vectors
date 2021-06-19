#include<iostream>
#include"Line.h"
#include"Point.h"
#include"Segment.h"
#include"Triangle.h"
#include"Vector.h"
#include "Tetrahedron.h"
#include"Menu.h"
#include <fstream>
#include <string>
using namespace std;


int printMenu() {
	vector<Element*>container;
	cout << endl << "0 - Exit" << endl;
	cout << endl << "1 - Point" << endl;
	cout << endl << "2 - Vector" << endl;
	cout << endl << "3 - Line" << endl;
	cout << endl << "4 - Segment" << endl;
	cout << endl << "5 - Triangle" << endl;
	cout << endl << "6 - Tetrahedron" << endl;

	int option;


	while (true) {
		cout << "Please enter geometrical object: " << endl;
		cin >> option;
		if (option < 0 || option > 6) {
			cout << "Wrong! Please choose again: " << endl;
			cin >> option;
		}
		else if (option == 0) {
			saveContainerInFile(container);

			cout << "Successfully exited the program! Have an amazing day :)";
			break;
		}
		else {
			switch (option)
			{
			case 1:
				printAllPointOperations(container);
				break;
			case 2:
				printAllVectorOperations(container);
				break;
			case 3:
				printAllLineOperations(container);
				break;
			case 4:
				printAllSegmentOperations(container);
				break;
			case 5:
				printAllTriangleOperations(container);
				break;
			case 6:
				printAllTetrahedronOperations(container);
				break;
			}

		}


	}

	return 0;
}

int printAllPointOperations(std::vector<Element*>& container) {
	int chooseOperation;
	Point p;
	cin >> p;

	while (true) {
		cout << endl << endl;
		cout << "Please enter operation for the object: " << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Find in which quadrant the point is" << endl;
		cout << "2 - Find if two points are equal" << endl;
		cout << endl << endl;
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
	container.push_back(new Point(p.getX(), p.getY(), p.getZ()));
	return 0;
}

int printAllVectorOperations(std::vector<Element*>& container) {
	int chooseOperation;
	Vector v;
	cin >> v;

	while (true) {
		cout << endl << endl;
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
		cout << endl << endl;
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
	container.push_back(new Vector(v.getX(), v.getY(), v.getZ()));
	return 0;
}



int printAllLineOperations(std::vector<Element*>& container) {
	Line l;
	cin >> l;
	int chooseOperation;

	while (true)
	{
		cout << endl << endl;
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
		cout << endl << endl;
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
				Vector normalVector = l.findNormalVector();
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
	Point* point = new Point(l.getPoint1().getX(), l.getPoint1().getY(), l.getPoint1().getZ());
	Vector* vector = new Vector(l.getX(), l.getY(), l.getZ());

	container.push_back(new Line(*point, *vector));
	if (point != nullptr)
	{
		delete point;
		point = nullptr;
	}
	if (vector != nullptr)
	{
		delete vector;
		vector = nullptr;
	}
	return 0;
}


int printAllSegmentOperations(std::vector<Element*>& container) {
	int chooseOperation;
	Segment s;
	cin >> s;

	while (true)
	{
		cout << endl << endl;
		cout << "Please enter operation for the object: " << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Find length of segment" << endl;
		cout << "2 - Find center of segment" << endl;
		cout << "3 - Draw segment" << endl;
		cout << endl << endl;
		cin >> chooseOperation;
		if (chooseOperation < 0 || chooseOperation > 3) {
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
			{
				Point result = s.middle();
				cout << result << endl;
				break;
			}
			case 3:
			{
				cout << s;
				break;
			}
			}
		}


	}
	Point* S = new Point(s.getS().getX(), s.getS().getY(), s.getS().getZ());
	Point* E = new Point(s.getE().getX(), s.getE().getY(), s.getE().getZ());

	container.push_back(new Segment(*S, *E));
	if (S != nullptr)
	{
		delete S;
		S = nullptr;
	}
	if (E != nullptr)
	{
		delete E;
		E = nullptr;
	}
	return 0;
}



int printAllTriangleOperations(std::vector<Element*>& container) {
	Triangle t;
	cin >> t;
	int chooseOperation;

	while (true)
	{
		cout << endl << endl;
		cout << "Please enter operation for the object: " << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Find type of triangle" << endl;
		cout << "2 - Find area of triangle" << endl;
		cout << "3 - Find perimeter of triangle" << endl;
		cout << "4 - Find medicenter of triangle" << endl;
		cout << "5 - Find if a point lies on the same plane as the triangle's and it is INSIDE of it" << endl;
		cout << "6 - Find if a point lies on the same plane as the triangle's and it is OUTSIDE of it" << endl;
		cout << "7 - Find if a point lies on the same plane as the triangle's and LIES on any line of it" << endl;
		cout << "8 - Draw triangle" << endl;
		cout << endl << endl;
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
			{
				t.type();
				break;
			}
			case 2:
				cout << "Area of triangle is: " << t.area() << endl;
				break;
			case 3:
				cout << "Perimeter of triangle is: " << t.perimeter() << endl;
				break;
			case 4:
				cout << "Medicenter of triangle is: " << t.medicenter() << endl;
				break;
			case 5:  // inside
			{
				Point p;
				cin >> p;
				if (t > p and p < t) {  // both operators works( point can be left or right hand side )
					cout << "Point lies on the same plane as the triangle and it is inside of it" << endl;
				}
				else {
					cout << "Point is not inside of triangle" << endl;
				}
				break;
			}
			case 6:  // outside
			{
				Point p;
				cin >> p;
				if (t < p) {
					cout << "Point lies on the same plane as the triangle and it is outside of it" << endl;
				}
				else {
					cout << "Point is not outside of triangle" << endl;
				}
				break;
			}

			case 7:  // lies
			{
				Point p;
				cin >> p;
				if (t == p) {
					cout << "Point lies on the same plane as the triangle's and lies on any line of it" << endl;
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
	Point* A = new Point(t.getA().getX(), t.getA().getY(), t.getA().getZ());
	Point* B = new Point(t.getB().getX(), t.getB().getY(), t.getB().getZ());
	Point* C = new Point(t.getC().getX(), t.getC().getY(), t.getC().getZ());

	container.push_back(new Triangle(*A, *B, *C));
	if (A != nullptr)
	{
		delete A;
		A = nullptr;
	}
	if (B != nullptr)
	{
		delete B;
		B = nullptr;
	}
	if (C != nullptr)
	{
		delete C;
		C = nullptr;
	}
	return 0;
}
int printAllTetrahedronOperations(std::vector<Element*>& container) {
	Tetrahedron t = Tetrahedron();
	cin >> t;
	int chooseOperation;

	while (true)
	{
		cout << endl << endl;
		cout << "Please enter operation for the object: " << endl;
		cout << "0 - Exit" << endl;
		cout << "1 - Find if tetrahedron is regular" << endl;
		cout << "2 - Find if tetrahedron is orthocentric" << endl;
		cout << "3 - Find surface area" << endl;
		cout << "4 - Find volume" << endl;
		cout << "5 - Draw tetrahedron" << endl;
		cout << "6 - Check if a point LIES on a tetrahedron" << endl;
		cout << "7 - Check if a point is INSIDE a tetrahedron" << endl;
		cout << "8 - Check if a point is OUTSIDE a tetrahedron" << endl;

		cout << endl << endl;
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
				if (t.isRegular())
				{
					cout << "Tetrahedron is regular" << endl;
				}
				else
				{
					cout << "Tetrahedron is not regular" << endl;
				}
				break;
			case 2:
				if (t.isOrthocentric())
				{
					cout << "Tetrahedron is orthocentric" << endl;
				}
				else
				{
					cout << "Tetrahedron is not orthocentric" << endl;
				}
				break;
			case 3:
				cout << "Surface area of tetrahedron is: " << t.surfaceArea() << endl;
				break;
			case 4:
				cout << "Volume of tetrahedron is:  " << t.volume() << endl;
				break;
			case 5:
				cout << t;
				break;
			case 6:  // lies
			{
				Point p;
				cin >> p;
				if (p == t) cout << "Yes, Point lies on any edge of tetrahedron\n";
				else cout << "No, Point does not lie on any edge of tetrahedron\n";
				break;
			}
			case 7:  // inside
			{
				Point p;
				cin >> p;
				if (p < t or t > p) cout << "Yes, Point is inside of tetrahedron\n";
				else cout << "No, Point is not inside of tetrahedron\n";
				break;
			}
			case 8:  // outside
			{
				Point p;
				cin >> p;
				if (p > t) cout << "Yes, Point is outside of tetrahedron\n";
				else cout << "No, Point is not outside of tetrahedron\n";
				break;
			}
			}
		}
	}
	Point* A = new Point(t.getA().getX(), t.getA().getY(), t.getA().getZ());
	Point* B = new Point(t.getB().getX(), t.getB().getY(), t.getB().getZ());
	Point* C = new Point(t.getC().getX(), t.getC().getY(), t.getC().getZ());
	Point* D = new Point(t.getD().getX(), t.getD().getY(), t.getD().getZ());
	container.push_back(new Tetrahedron(*A, *B, *C, *D));
	if (A != nullptr)
	{
		delete A;
		A = nullptr;
	}
	if (B != nullptr)
	{
		delete B;
		B = nullptr;
	}
	if (C != nullptr)
	{
		delete C;
		C = nullptr;
	}
	if (D != nullptr)
	{
		delete D;
		D = nullptr;
	}
	return 0;
}
int saveContainerInFile(std::vector<Element*>& container)
{
	cout << "Do you want to save the objects you have created ? y/n" << std::endl;
	char answer;
	cin >> answer;
	while (true)
	{
		if (answer == 'y' || answer == 'n')
		{
			break;
		}
		std::cout << "Enter y or n !" << std::endl;
		std::cin >> answer;
	}
	if (answer == 'y')
	{
		std::ofstream writer("Objects-Container.txt");
		int index = 1;
		for (std::vector<Element*>::iterator it = container.begin(); it < container.end(); it++)
		{

			writer << "Object: " << index << endl;
			if (typeid(**it) == typeid(Vector))
			{
				writer << "Vector" << endl;
				Vector* v = dynamic_cast<Vector*>(*it);
				writer << *v;
			}
			else if (typeid(**it) == typeid(Point))
			{
				writer << "Point" << endl;
				Point* v = dynamic_cast<Point*>(*it);
				writer << *v;
			}
			else if (typeid(**it) == typeid(Line))
			{
				writer << "Line" << endl;
				Line* l = dynamic_cast<Line*>(*it);
				writer << *l;
			}
			else if (typeid(**it) == typeid(Segment))
			{
				writer << "Segment" << endl;
				Segment* s = dynamic_cast<Segment*>(*it);
				writer << *s;
			}
			else if (typeid(**it) == typeid(Triangle))
			{
				writer << "Triangle" << endl;
				Triangle* t = dynamic_cast<Triangle*>(*it);
				writer << *t;
			}
			else if (typeid(**it) == typeid(Tetrahedron)) {
				writer << "Tetrahedron" << endl;
				Tetrahedron* t = dynamic_cast<Tetrahedron*>(*it);
				writer << *t;
			}
			index++;

		}
		writer.close();
		return 0;
	}
	return 0;

}