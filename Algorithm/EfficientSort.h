#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �� ����
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(NlogN)
	for (int num : v)
		pq.push(num);

	v.clear();

	// O(NlogN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}

// ���� ����
// ���� ���� (Divide and Conquer)
// - ���� (Divide)		������ �� �ܼ��ϰ� �����Ѵ�
// - ���� (Conquer)		���ҵ� ������ �ذ�
// - ���� (Combine)		����� �����Ͽ� ������

// O(NlogN)
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// [2][3][7][4][8][9]
	// [l]   [m]      [r]
	int leftIdx = left;
	int rightIdx = mid + 1;

	// [2]
	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] <= v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	// ������ ���� ��������, ������ ������ ������ ����
	if (leftIdx > mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	// �������� ���� ��������, ���� ������ ������ ����
	else
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
		v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);

	MergeResult(v, left, mid, right);
}
