#pragma once
#include <iostream>
using namespace std;
class  Vector
{
private:
	int* els;
	int cur_size;
	int buf_size;

public:
	 Vector();
	 Vector(int size);
	 Vector(const Vector& obj);

	 int operator[](int index);
	 Vector operator+(Vector obj);
	 Vector operator-(Vector obj);
	 Vector operator<<(int index);
	 Vector operator>>(int el);
	 void add(int el);
	 int at(int index);
	 void remove_by_index(int index);
	 int size();

	~ Vector();



};
