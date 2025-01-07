#pragma once
#include <stdexcept>

template<typename T>
class MyVector
{
public:
	MyVector()
	{

	}

	~MyVector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		if (_size == _capacity)// ��ó�� or �迭�� ���� ���
		{
			// ���� �۾�
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// ������ ����
		_data[_size] = value;

		// ������ ���� ����
		_size++;
	}

	void resize(int size, const T& value = T())
	{
		if (_size == size)
			return;

		if (_size > size)// size�� �۾��� ���
		{
			// []�����ڷ� ������ �����⿡ size�� �ٿ���
			_size = size;

			// capacity�� ����
		}
		else// size�� Ŀ�� ���
		{
			if(size > _capacity)// capacity���� ū ��쿡�� capacity Ȯ��(���Ҵ�)
				reserve(size);

			// �þ �κ� �ʱⰪ ����
			for (int i = _size; i < size; i++)
				_data[i] = value;

			_size = size;
		}
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		// ���ο� ������ �����Ҵ�
		T* newData = new T[_capacity];

		// ������ ����
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// ���� ������ ����
		if (_data)
			delete[] _data;

		// ��ü
		_data = newData;
	}

	void clear()
	{
		// ���� capacity�� �����ϰ� ���Ҵ��ϴ� ���
		// ����, ���� ���� ��Ȱ���ϴ� ����� �Ϸ��� 
		// _size�� 0���� �ϸ� ��
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}

		_size = 0;// size�� 0����
	}

	T& operator[](const int pos) 
	{ 
		if (pos < 0 || pos >= _size)
			throw std::out_of_range("Index out of range");

		return _data[pos]; 
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _data = nullptr;// �迭�� ���� �ּ�
	int		_size = 0;// size
	int		_capacity = 0;// capacity
};