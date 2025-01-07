#pragma once
#include <vector>
#include <list>
using namespace std;

// [frontback][][][][][][][][][][][][][][][]
// [front][][][][][][][][][][][back][][][][]
// [][front][][][][][][][][][][back][][][][] POP
// [][front][][][][][][][][][][][back][][][] PUSH

// [][][][back][][][][][][][front][][][][][] ��ȯ

template<typename T>
class MyVectorQueue
{
public:
	MyVectorQueue()
	{
		//_container.resize(100);
	}

	void push(const T& value)
	{
		if (_size == _container.size())// �� �� ���
		{
			// ���� �۾�
			int newSize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newSize);

			// ������ ����
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container;

	int _front = 0;
	int _back = 0;// rear or back
	int _size = 0;
};

template<typename T>
class MyListQueue
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_front();
	}

	T& front()
	{
		return _container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	list<T> _container;
};
