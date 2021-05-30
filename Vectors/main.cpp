#include <iostream>
#include "Menu.h"
#include "MenuFile.h"
#include "Tetrahedron.h"
#include "TestLine.h"
#include "TestTriangle.h"


using namespace std;

int main() {

	
	cout << "Choose between options 1 or 2" << endl;
	cout << "1.Menu without file" << endl << "2.Menu with file" << endl;
	int option;
	cin >> option;
	while (true)
	{
		if (option == 1 || option == 2)
		{
			break;
		}
		cout << "Not a valid option try again !" << endl;
		cin >> option;
	}
	try
	{

		switch (option)
		{
		case 1:
			printMenu();
			break;
		case 2:
			printMenuFile();
			break;

		}
	}
	catch (const std::exception& e)
	{
		cout << e.what();
	}

	




}