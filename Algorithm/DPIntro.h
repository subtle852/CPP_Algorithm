#pragma once

int combination(int n, int r)
{
	if (r == 0 || n == r)
		return 1;

	return combination(n - 1, r - 1) + combination(n - 1, r);
};

int CombinationCache[50][50];

int combination_memo(int n, int r)
{
	// 기저 사례
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = CombinationCache[n][r];
	if (ret != -1)
		return ret;

	// 새로 답을 구해서 캐시에 저장
	return ret = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r);
};



