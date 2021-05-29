#ifndef MenuFile_hh
#define MenuFile_hh
#include<iostream>
#include "Element.h"
#include"Line.h"
#include"Point.h"
#include"Segment.h"
#include"Triangle.h"
#include"Vector.h"
#include "Tetrahedron.h"
#include"Menu.h"
#include "FileException.h"

int printMenuFile();
Point* parsePoint(const char*);
Vector* parseVector(const char*);
Line* parseLine(const char*);
Segment* parseSegment(const char*);
Triangle* parseTriangle(const char*);
Tetrahedron* parseTetrahedron(const char*);
int runTask(int, int, Element*&, const char*);
#endif // !MenuFile_hh

