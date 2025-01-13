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

		// 제일 마지막 위치
		int now = static_cast<int>(_heap.size()) - 1;
		
		// 루트 노드까지 반복
		while (now > 0)
		{
			// 부모 노드와 비교해서 더 작은 or 큰 (Predicate에 따라) 경우 교체
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

			// 리프에 도달한 경우
			if (left >= (int)_heap.size())
				break;

			// 왼쪽과 비교
			if (_predicate(_heap[next], _heap[left]))
				next = left;

			// 둘 중 승자를 오른쪽과 비교
			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
				next = right;

			// 왼쪽/오른쪽 둘 다 현재 값보다 작으면 종료
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
