#pragma once
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
class MyPriorityQueue
{
public:
	void push(const T& data)
	{
		_heap.push_back(data);

		// ���� ������ ��ġ
		int now = static_cast<int>(_heap.size()) - 1;
		
		// ��Ʈ ������ �ݺ�
		while (now > 0)
		{
			// �θ� ���� ���ؼ� �� ���� or ū (Predicate�� ����) ��� ��ü
			int next = (now - 1) / 2;
			if (_predicate(_heap[now], _heap[next]))
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;
			int next = now;

			// ������ ������ ���
			if (left >= (int)_heap.size())
				break;

			// ���ʰ� ��
			if (_predicate(_heap[next], _heap[left]))
				next = left;

			// �� �� ���ڸ� �����ʰ� ��
			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// ����/������ �� �� ���� ������ ������ ����
			if (next == now)
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	Container _heap = {};
	Predicate _predicate = {};
};
