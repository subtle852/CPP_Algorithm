#pragma once

int LisCache[100];
vector<int> seq;

int lis(int pos)
{
	// 기저 사항

	// 캐시 확인
	int& ret = LisCache[pos];
	if (ret != -1)
		return ret;

	// 구하기

	// 최소 seq[pos]은 있으니 1부터 시작
	ret = 1;

	// 구하기
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + lis(next));

	return ret;
};
