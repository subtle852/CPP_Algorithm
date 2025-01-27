#pragma once
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> cache;
vector<vector<int>> nextX;

int path(int y, int x)
{
	// 기저 사항
	// 1번 방식
	// if (y == N - 1)
	//	return board[y][x];
	
	// 2번 방식
	if (y == N)
		return 0;

	// 캐시 확인
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	// 경로 기록
	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x + 1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}

	// 적용
	return ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}
