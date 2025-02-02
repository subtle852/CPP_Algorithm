#pragma once
#include <iostream>
using namespace std;

// ����
// +0 �����
// ���� ��ȭ �ֹ��� Ȯ��: +1 / +2 / +3 �� �ϳ�

// +9�� ���Ⱑ �ߴ� ����� ����?
// ex) +1 +2 +3 +4 ... +9
// ex) +3 +6 +9
// ex) +1 +3 +4 

int N;
int cache[100];

int Enchant(int num)
{
	// ���� ���
	if (num > N)
		return 0;
	if (num == N)
		return 1;

	// ĳ��
	int& ret = cache[num];
	if (ret != -1)
		return ret;

	// ����
	return ret = Enchant(num + 1) + Enchant(num + 2) + Enchant(num + 3);
}
