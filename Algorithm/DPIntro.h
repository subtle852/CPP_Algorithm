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
	// ���� ���
	if (r == 0 || n == r)
		return 1;

	// �̹� ���� ���� �� ������ �ٷ� ��ȯ
	int& ret = CombinationCache[n][r];
	if (ret != -1)
		return ret;

	// ���� ���� ���ؼ� ĳ�ÿ� ����
	return ret = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r);
};



