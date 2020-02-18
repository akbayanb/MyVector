#include "Vector.h"

int main() {
	Vector v;
	v>>5, v>>7;
	v>>8;
	v>>2;
	v>>12;
	v << 0;
	Vector v1;
	v1.add(8);
	v1.add(15);

	 v - v1;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	system("pause");
}