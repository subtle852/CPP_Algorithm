#include <iostream>
#include <vector>
#include "MyVector.h"
using namespace std;


int main()
{
	//vector<int> v;
	MyVector<int> v;

	v.reserve(100);
	cout << v.size() << " " << v.capacity() << endl;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.resize(10);
	cout << v.size() << " " << v.capacity() << endl;

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
}