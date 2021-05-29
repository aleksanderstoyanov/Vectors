#include "MenuFile.h"
#include <fstream>
#include <vector>
int printMenuFile() {

	std::vector<Element*>container;
	int index = 0;


	std::ifstream reader("FileMenu.txt");
	if (!reader)
	{
		std::cout << "Invalid file !";
		return -1;
	}
	int option = -1, taskForObject = -1;
	char buffer[50];
	unsigned line = 0;
	while (reader.getline(buffer, 49))
	{
		if (line == 0)
		{
			if (strlen(buffer) > 2)
			{
				throw FileException();
				return -2;
			}
			unsigned parsedOption = buffer[0] - '0';
			if (parsedOption < 1 || parsedOption>6)
			{
				throw FileException();
				return -3;
			}

			option = parsedOption;
			line++;
			continue;
		}
		if (line == 1)
		{
			if (option < 1 || option>6)
			{
				throw FileException();
				return -4;
			}
			else {
				switch (option)
				{
				case 1:// Point
				{
					std::cout << "Object is Point" << std::endl;
					Point* point = parsePoint(buffer);
					container.push_back(point);
					break;
				}

				case 2:// Vector
				{
					std::cout << "Object is Vector" << std::endl;
					Vector* vector = parseVector(buffer);
					container.push_back(vector);
					break;
				}
				case 3:// Line
				{
					std::cout << "Object is Line" << std::endl;
					Line* line = parseLine(buffer);
					container.push_back(line);
					break;
				}
				case 4:// Segment
				{
					std::cout << "Object is Segment" << std::endl;
					Segment* segment = parseSegment(buffer);
					container.push_back(segment);
					break;
				}
				case 5:// Triangle
				{
					std::cout << "Object is Triangle" << std::endl;
					Triangle* triangle = parseTriangle(buffer);
					container.push_back(triangle);
					break;
				}
				case 6://Tetrahedron
				{
					std::cout << "Object is Tetrahedron" << std::endl;
					Tetrahedron* tetrahedron = parseTetrahedron(buffer);
					container.push_back(tetrahedron);
					break;
				}
				}

			}
			line++;
			continue;
		}
		if (line == 2)
		{
			if (strlen(buffer) > 2)
			{
				throw FileException();
				return -2;
			}
			unsigned parsedTask = buffer[0] - '0';
			if (parsedTask < 1)
			{
				throw FileException();
				return -3;
			}
			taskForObject = parsedTask;
			line++;
			continue;
		}
		if (line == 3)
		{
			if (taskForObject <= 0)
			{
				throw FileException();
			}

			Element* el = container.front();

			runTask(option, taskForObject, el, buffer);
			line++;
			continue;
		}

	}
	reader.close();
	/*std::cout << "Do you want to save the objects you have created ? y/n" << std::endl;
	char answer;
	std::cin >> answer;*/
	//while (true)
	//{
	//	if (answer=='y'||answer=='n')
	//	{
	//		break;
	//	}
	//	std::cout << "Enter y or n !" << std::endl;
	//	std::cin >> answer;
	//}
	//if (answer=='y')
	//{
	//	std::ofstream writer("Result.txt");
	//	
	//	for (std::vector<Element*>::iterator it=container.begin();it<container.end();it++)
	//	{
	//		Vector* v = dynamic_cast<Vector*>(*it);
	//		writer << v << std::endl;
	//	}
	//	writer.close();
	//}

	std::cout << "Goodbye :)" << std::endl;
	return 0;
}

Point* parsePoint(const char* buffer) {
	double parameters[3];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 3 || numberOfArguments>4)
	{
		throw FileException();
		//throw FileException
	}

	return new Point(parameters[0], parameters[1], parameters[2]);
}
Vector* parseVector(const char* buffer) {
	double parameters[3];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 3 || numberOfArguments>3)
	{
		throw FileException();
		//throw FileException
	}

	return new Vector(parameters[0], parameters[1], parameters[2]);
}
Line* parseLine(const char* buffer) {
	double parameters[6];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != ',')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 6 || numberOfArguments>6)
	{
		throw FileException();
		//throw FileException
	}
	Point p = Point(parameters[0], parameters[1], parameters[2]);
	Vector v = Vector(parameters[3], parameters[4], parameters[5]);

	return new Line(p, v);
}
Segment* parseSegment(const char* buffer) {
	double parameters[6];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' || buffer[i] != ',')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 6 || numberOfArguments>6)
	{
		throw FileException();
		//throw FileException
	}
	Point p1 = Point(parameters[0], parameters[1], parameters[2]);
	Point p2 = Point(parameters[3], parameters[4], parameters[5]);

	return new Segment(p1, p2);
}
Triangle* parseTriangle(const char* buffer) {
	double parameters[9];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != ',')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 9 || numberOfArguments>9)
	{
		throw FileException();
		//throw FileException
	}
	Point p1 = Point(parameters[0], parameters[1], parameters[2]);
	Point p2 = Point(parameters[3], parameters[4], parameters[5]);
	Point p3 = Point(parameters[6], parameters[7], parameters[8]);

	return new Triangle(p1, p2, p3);
}
Tetrahedron* parseTetrahedron(const char* buffer) {
	double parameters[12];
	int numberOfArguments = 0;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] != ' ' && buffer[i] != ',')
		{
			parameters[numberOfArguments++] = buffer[i] - '0';
		}
	}
	if (numberOfArguments < 12 || numberOfArguments>12)
	{
		throw FileException();
		//throw FileException
	}
	Point p1 = Point(parameters[0], parameters[1], parameters[2]);
	Point p2 = Point(parameters[3], parameters[4], parameters[5]);
	Point p3 = Point(parameters[6], parameters[7], parameters[8]);
	Point p4 = Point(parameters[9], parameters[10], parameters[11]);


	return new Tetrahedron(p1, p2, p3, p4);
}
int runTask(int option, int task, Element*& obj, const char* buffer) {
	switch (option)
	{
	case 1:
	{
		if (task < 1 || task>2)
		{
			throw FileException();
		}
		Point* p = dynamic_cast<Point*>(obj);
		std::cout << *p;
		if (task == 1)
		{
			std::cout << "Task running...(Find quadrant of point)" << std::endl;
			std::cout << "Point is in " << p->quadrant() << std::endl;
		}
		else if (task == 2)
		{
			std::cout << "Task running...(Find if two points are equal)" << std::endl;
			Point* p2 = parsePoint(buffer);
			if (p == p2)
			{
				std::cout << "Points are equal !" << std::endl;
			}
			else {
				std::cout << "Points are not equal !" << std::endl;
			}
			if (p2 != nullptr)
			{
				delete p2;
				p2 = nullptr;
			}
		}
		if (p != nullptr)
		{
			delete p;
			p = nullptr;
		}
		break;
	}
	case 2:
	{

		Vector* v = dynamic_cast<Vector*>(obj);
		std::cout << *v;
		if (task < 1 || task>10)
		{
			throw FileException();
		}
		if (task == 1)
		{
			std::cout << "Task running...(Find length of vector)" << std::endl;
			std::cout << "Vector length is: " << v->length() << std::endl;

		}
		else if (task == 2)
		{
			std::cout << "Task running...(Find length of vector)" << std::endl;
			Vector result = v->direction();
			std::cout << "Length of vector is: " << std::endl;
			std::cout << result;

		}
		else if (task == 3)
		{
			std::cout << "Task running...(check for zero vector)" << std::endl;
			if (v->isNull())
			{
				std::cout << "Vector is null" << std::endl;
			}
			else {
				std::cout << "Vector is not null" << std::endl;
			}
		}
		else if (task == 4)
		{
			std::cout << "Task running...(check for parallelism of two vectors)" << std::endl;
			Vector* v2 = parseVector(buffer);
			if (v->parallel(*v2))
			{
				std::cout << "Vectors are parallel" << std::endl;

			}
			else {
				std::cout << "Vector are not parallel" << std::endl;
			}
			if (v2 != nullptr)
			{
				delete v2;
				v2 = nullptr;
			}
		}
		else if (task == 5)
		{
			std::cout << "Task running...(check for perpendicularity of two vectors)" << std::endl;
			Vector* v2 = parseVector(buffer);
			if (v->perpendicular(*v2))
			{
				std::cout << "Vectors are perpendicular" << std::endl;

			}
			else {
				std::cout << "Vector are not perpendicular" << std::endl;
			}

		}
		else if (task == 6)
		{
			std::cout << "Task running...(addition of two vectors)" << std::endl;
			Vector* v2 = parseVector(buffer);
			std::cout << *v2;
			Vector result = *v + *v2;
			std::cout << "Addition of two vectors is: " << std::endl;
			std::cout << result;

			if (v2 != nullptr)
			{
				delete v2;
				v2 = nullptr;
			}

		}
		else if (task == 7)
		{
			std::cout << "Task running...(multiplication of a vector by a real number)" << std::endl;
			double realNumber;
			std::cout << "Enter real number: ";
			std::cin >> realNumber;

			Vector result = *v * realNumber;
			std::cout << "Result vector is: " << std::endl << result;
			//subtraction of vectors
		}
		else if (task == 8)
		{
			std::cout << "Task running...(scalar product of two vectors)" << std::endl;
			double result;
			Vector* v2 = parseVector(buffer);
			result = (*v) * (*v2);
			std::cout << "Scalar product of the two vectors is:" << result;
			if (v2 != nullptr)
			{
				delete v2;
				v2 = nullptr;
			}
		}
		else if (task == 9)
		{
			std::cout << "Task running...(vector product of two vectors)" << std::endl;
			Vector* v2 = parseVector(buffer);
			Vector result = (*v) ^ (*v2);
			std::cout << "Vector product of the two vectors is: " << std::endl << result;
			if (v2 != nullptr)
			{
				delete v2;
				v2 = nullptr;
			}

		}
		// TO DO: Implement Cross product
		if (v != nullptr)
		{
			delete v;
			v = nullptr;
		}
		break;
	}
	case 3:
	{

		if (task < 1 || task>10)
		{
			throw FileException();
		}
		Line* line = dynamic_cast<Line*>(obj);
		std::cout << *line;
		if (task == 1)
		{
			std::cout << "Task running...(find line direction)" << std::endl;
			Vector direction = line->direction();
			std::cout << "Direction vector is : " << std::endl << direction;
		}
		else if (task == 2)
		{
			std::cout << "Task running...(find normal vector)" << std::endl;
			Vector normal = line->findNormalVector();
			std::cout << "Normal vector is : " << std::endl << normal;
		}
		else if (task == 3)
		{
			std::cout << "Task running...(find angle between two lines)" << std::endl;
			Line* line2 = parseLine(buffer);
			double angle = line->findAngleOfBetweenTwoLines(*line2);
			std::cout << "Angle between the two lines is: " << angle << std::endl;
			if (line2 != nullptr)
			{
				delete line2;
				line2 = nullptr;
			}

		}
		else if (task == 4) {
			std::cout << "Task running...(find if a given point lies on a line)" << std::endl;
			Point* p = parsePoint(buffer);
			if (*line + *p)
			{
				std::cout << "Point lies on the line" << std::endl;
			}
			else {
				std::cout << "Point does not lie on the line" << std::endl;
			}
			if (p != nullptr)
			{
				delete p;
				p = nullptr;
			}
		}
		else if (task == 5)
		{
			std::cout << "Task running...(find if two lines are parallel)" << std::endl;
			Line* l2 = parseLine(buffer);
			if (*line || *l2)
			{
				std::cout << "The lines are parallel" << std::endl;
			}
			else {
				std::cout << "The lines are not parallel" << std::endl;
			}
			if (l2 != nullptr)
			{
				delete l2;
				l2 = nullptr;
			}
		}
		else if (task == 6)
		{
			std::cout << "Task running...(find if two lines coincide)" << std::endl;
			Line* l2 = parseLine(buffer);
			if (*line == *l2)
			{
				std::cout << "The lines coincide" << std::endl;
			}
			else {
				std::cout << "The lines do not coincide" << std::endl;
			}
			if (l2 != nullptr)
			{
				delete l2;
				l2 = nullptr;
			}
		}
		else if (task == 7)
		{
			std::cout << "Task running...(find if two lines intersect)" << std::endl;
			Line* l2 = parseLine(buffer);
			if (*line && *l2)
			{
				std::cout << "The lines intersect" << std::endl;
			}
			else {
				std::cout << "The lines do not intersect" << std::endl;
			}
			if (l2 != nullptr)
			{
				delete l2;
				l2 = nullptr;
			}
		}
		else if (task == 8)
		{
			std::cout << "Task running...(find if two lines are skew)" << std::endl;
			Line* l2 = parseLine(buffer);
			if (*line != *l2)
			{
				std::cout << "The lines are skew" << std::endl;
			}
			else {
				std::cout << "The lines are not skew" << std::endl;
			}
			if (l2 != nullptr)
			{
				delete l2;
				l2 = nullptr;
			}
		}
		else if (task == 9)
		{
			std::cout << "Task running...(find if two lines are perpendicular)" << std::endl;
			Line* l2 = parseLine(buffer);
			if (*line | *l2)
			{
				std::cout << "The lines are perpendicular" << std::endl;
			}
			else {
				std::cout << "The lines are not perpendicular" << std::endl;
			}
			if (l2 != nullptr)
			{
				delete l2;
				l2 = nullptr;
			}
		}
		else if (task == 10)
		{
			std::cout << "Task running...(Draw line)" << std::endl;
			std::cout << line;
		}
		if (line != nullptr)
		{
			delete line;
			line = nullptr;
		}
		break;
	}
	case 4:
	{
		if (task < 1 || task>2)
		{
			throw FileException();
		}
		Segment* seg = dynamic_cast<Segment*>(obj);
		std::cout << *seg;
		if (task == 1)
		{
			std::cout << "Task running...(find length of segment)" << std::endl;
			double length = seg->length();
			std::cout << "Length of segment is: " << length << std::endl;
		}
		else if (task == 2)
		{
			std::cout << "Task running...(Find center of segment)" << std::endl;
			std::cout << "Center of segment is: " << std::endl << seg->middle();
		}
		if (seg != nullptr)
		{
			delete seg;
			seg = nullptr;
		}
		break;
	}
	case 5:
	{

		if (task < 1 || task>8)
		{
			throw FileException();
		}
		Triangle* t = dynamic_cast<Triangle*>(obj);
		std::cout << *t;
		if (task == 1)
		{
			std::cout << "Task running...(find type of triangle)" << std::endl;
			std::cout << "Type of triangle is: " << t->type();
		}
		else if (task == 2)
		{
			std::cout << "Task running...(find area of triangle)" << std::endl;
			std::cout << "Area of triangle is: " << t->area();

		}
		else if (task == 3) {
			std::cout << "Task running...(find perimeter of triangle)" << std::endl;
			std::cout << "Perimeter of triangle is: " << t->perimeter();

		}
		else if (task == 4)
		{
			std::cout << "Task running...(find medicenter of triangle)" << std::endl;
			std::cout << "Medicenter of triangle is: " << t->perimeter();
		}
		else if (task == 5)
		{
			std::cout << "Task running...(find if a point lies on the same plane as the triangle's and if it is inside him)" << std::endl;
			Point* p = parsePoint(buffer);
			if (*t < *p) {
				std::cout << "Point lies on the same plane as the triangle and it is inside him" << std::endl;
			}
			else {
				std::cout << "Point does not lie on the same plane as the triangle and it is inside him" << std::endl;
			}
			if (p != nullptr)
			{
				delete p;
				p = nullptr;
			}
		}
		else if (task == 6)
		{
			std::cout << "Task running...(find if a point lies on the same plane as the triangle's and if it is outside of him)" << std::endl;
			Point* p = parsePoint(buffer);
			if (*t > *p) {
				std::cout << "Point lies on the same plane as the triangle and it is outside him" << std::endl;
			}
			else {
				std::cout << "Point does not lie on the same plane as the triangle and it is outside him" << std::endl;
			}
			if (p != nullptr)
			{
				delete p;
				p = nullptr;
			}
		}
		else if (task == 7)
		{
			std::cout << "Task running...(Find if a point lies on a given line of the triangle's)" << std::endl;
			Point* p = parsePoint(buffer);
			if (*t == *p) {
				std::cout << "Point lies on at least on one side of the triangle" << std::endl;
			}
			else {
				std::cout << "Point does not lie on neither of the triangle's sides" << std::endl;
			}
		}
		else if (task == 8)
		{
			std::cout << "Task running...(Draw triangle)" << std::endl;
			std::cout << *t;
		}
		if (t != nullptr)
		{
			delete t;
			t = nullptr;
		}
		break;

	}
	case 6:
	{
		if (task < 1 || task>5)
		{
			throw FileException();
		}
		Tetrahedron* t = dynamic_cast<Tetrahedron*>(obj);
		std::cout << *t;
		if (task == 1)
		{
			std::cout << "Task running...(find if tetrahedron is regular)" << std::endl;
			if (t->isRegular())
			{
				std::cout << "Tetrahedron is regular" << std::endl;
			}
			else {
				std::cout << "Tetrahedron is not regular" << std::endl;
			}

		}
		else if (task == 2)
		{
			std::cout << "Task running...(find if tetrahedron is orthocentric)" << std::endl;
			if (t->isOrthocentric())
			{
				std::cout << "Tetrahedron is orthocentric" << std::endl;
			}
			else {
				std::cout << "Tetrahedron is not orthocentric" << std::endl;
			}
		}
		else if (task == 3)
		{
			std::cout << "Task running...(find if surface area of tetrahedron)" << std::endl;
			std::cout << "Surface area of tetrahedron is " << t->surfaceArea() << std::endl;
		}
		else if (task == 4)
		{
			std::cout << "Task running...(find if volume of tetrahedron)" << std::endl;
			std::cout << "Volume of tetrahedron is " << t->volume() << std::endl;
		}
		else if (task == 5)
		{
			std::cout << "Task running...(draw tetrahedron)" << std::endl;
			std::cout << "Drawing...." << std::endl;
			std::cout << *t;
		}

	}

	}

	return 0;
}