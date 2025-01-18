#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;

void BinarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "Ž�� ����: " << left << "~" << right << endl;

		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "ã��!" << endl;
			break;
		}
	}

}
