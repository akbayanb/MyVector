#include "Vector.h"

Vector::Vector()
{
	els = nullptr;
	cur_size = 0;
	buf_size = 0;
}

Vector::Vector(int size)
{
	els = new int[size];
	cur_size = 0;
	buf_size = size;
}

Vector::Vector(const Vector & obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.buf_size;
	this->els = new int[buf_size];
	for (int i = 0; i < cur_size; i++)
	{
		els[i] = obj.els[i];
	}
}

int Vector::operator[](int index)
{
	return els[index];
}

Vector Vector::operator+(Vector obj)
{	Vector rez(*this);
	for (int i = 0; i < obj.size(); i++)
		rez.add(obj[i]);
	return rez;}

Vector Vector::operator-(Vector obj)
{
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < obj.size(); j++) {
			if (els[i] == obj[j])
			{
				remove_by_index(i);
				i--;
			}
		}
	}
	return (*this);
}

Vector Vector::operator<<(int index)
{
	remove_by_index(index);
	return (*this);
}

Vector Vector::operator>>(int el)
{
	add(el);
	return *this;
}

void Vector::add(int el)
{
	if (cur_size == 0 && buf_size == 0)
	{	buf_size = 4;
		els = new int[buf_size];}
	if (cur_size >= buf_size) {
		buf_size *= 2;
		int* tmp = new int[buf_size];
		for (int i = 0; i < cur_size; i++) {
			tmp[i] = els[i];	}
		delete[] els;
		els = tmp;}
	els[cur_size++] = el;}

int Vector::at(int index)
{
	return els[index];
}

void Vector::remove_by_index(int index)
{
	for (int i = index; i < cur_size - 1; i++)
		swap(els[i], els[i + 1]);
	cur_size--;
}

int Vector::size()
{
	return cur_size;
}

Vector::~Vector()
{
	delete[] els;
}