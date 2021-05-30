#ifndef Menu
#define Menu
#include <iostream>
#include <vector>
#include "Element.h"

int printMenu();
int printAllPointOperations(std::vector<Element*>&);
int printAllVectorOperations(std::vector<Element*>&);
int printAllLineOperations(std::vector<Element*>&);
int printAllSegmentOperations(std::vector<Element*>&);
int printAllTriangleOperations(std::vector<Element*>&);
int printAllTetrahedronOperations(std::vector<Element*>&);
int saveContainerInFile(std::vector<Element*>&);
#endif 