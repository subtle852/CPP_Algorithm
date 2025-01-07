#include <iostream>
#include <vector>
#include "MyVector.h"
#include <list>
#include "MyList.h"
using namespace std;


int main()
{
	{
		////vector<int> v;
		//MyVector<int> v;

		//v.reserve(100);
		//cout << v.size() << " " << v.capacity() << endl;

		//for (int i = 0; i < 100; i++)
		//{
		//	v.push_back(i);
		//	cout << v.size() << " " << v.capacity() << endl;
		//}

		//v.resize(10);
		//cout << v.size() << " " << v.capacity() << endl;

		//v.clear();
		//cout << v.size() << " " << v.capacity() << endl;
	}

	{
		//list<int> li;
		MyList<int> li;

		MyList<int>::iterator eraseIt;

		for (int i = 0; i < 10; i++)
		{
			if (i == 5)
			{
				eraseIt = li.insert(li.end(), i);
			}
			else
			{
				li.push_back(i);
			}
		}

		li.pop_back();

		li.erase(eraseIt);

		for (MyList<int>::iterator it = li.begin(); it != li.end(); it++)
		{
			cout << (*it) << endl;
		}
	}
}