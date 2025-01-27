#pragma once
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<vector<int>> nextX;

int path(int y, int x)
{
	// ���� ����
	// 1�� ���
	// if (y == N - 1)
	//	return board[y][x];
	
	// 2�� ���
	if (y == N)
		return 0;

	// ĳ�� Ȯ��
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	// ��� ���
	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x + 1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}

	// ����
	return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}
