#pragma once
#include <iostream>
using namespace std;

// 문제
// +0 집행검
// 무기 강화 주문서 확률: +1 / +2 / +3 중 하나

// +9강 무기가 뜨는 경우의 수는?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// ex) +1 +3 +4 

int N;
int cache[100];

int Enchant(int num)
{
	// 기저 사례
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// 캐시
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// 적용
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}
