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
		if (_size == _capacity)// 맨처음 or 배열이 꽉찬 경우
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = value;

		// 데이터 개수 증가
		_size++;
	}

	void resize(int size, const T& value = T())
	{
		if (_size == size)
			return;

		if (_size > size)// size가 작아진 경우
		{
			// []연산자로 접근이 막히기에 size만 줄여줌
			_size = size;

			// capacity는 유지
		}
		else// size가 커진 경우
		{
			if(size > _capacity)// capacity보다 큰 경우에만 capacity 확장(재할당)
				reserve(size);

			// 늘어난 부분 초기값 설정
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

		// 새로운 데이터 동적할당
		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 기존 데이터 삭제
		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	void clear()
	{
		// 기존 capacity는 유지하고 재할당하는 방식
		// 만약, 기존 공간 재활용하는 방식을 하려면 
		// _size만 0으로 하면 됨
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}

		_size = 0;// size는 0으로
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
	T* _data = nullptr;// 배열의 시작 주소
	int		_size = 0;// size
	int		_capacity = 0;// capacity
};