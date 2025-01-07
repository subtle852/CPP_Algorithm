#include <iostream>
#include <vector>
#include "MyVector.h"
#include <list>
#include "MyList.h"
#include <stack>
#include "MyStack.h"
#include <queue>
#include "MyQueue.h"
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
		////list<int> li;
		//MyList<int> li;

		//MyList<int>::iterator eraseIt;

		//for (int i = 0; i < 10; i++)
		//{
		//	if (i == 5)
		//	{
		//		eraseIt = li.insert(li.end(), i);
		//	}
		//	else
		//	{
		//		li.push_back(i);
		//	}
		//}

		//li.pop_back();

		//li.erase(eraseIt);

		//for (MyList<int>::iterator it = li.begin(); it != li.end(); it++)
		//{
		//	cout << (*it) << endl;
		//}
	}

	{
		////stack<int> s;
		////stack<int, deque<int>> s;
		////stack<int, vector<int>> s;
		////stack<int, list<int>> s;
		//MyStack<int, list<int>> s;

		//// 삽입
		//s.push(1);
		//s.push(2);
		//s.push(3);

		//while (s.empty() == false)
		//{
		//	// 최상위 원소 삭제
		//	int data = s.top();
		//	s.pop();

		//	cout << data << endl;
		//}

		//int size = s.size();
	}

	{
		//queue<int> q;
		MyVectorQueue<int> q;
		//MyListQueue<int> q;

		for (int i = 0; i < 100; i++)
			q.push(i);

		while (q.empty() == false)
		{
			int value = q.front();
			q.pop();
			cout << value << endl;
		}

		int size = q.size();
	}
}