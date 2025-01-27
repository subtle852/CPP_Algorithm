#pragma once

int LisCache[100];
vector<int> seq;

int lis(int pos)
{
	// ���� ����

	// ĳ�� Ȯ��
	int& ret = LisCache[pos];
	if (ret != -1)
		return ret;

	// ���ϱ�

	// �ּ� seq[pos]�� ������ 1���� ����
	ret = 1;

	// ���ϱ�
	for (int next = pos + 1; next < seq.size(); next++)
		if (seq[pos] < seq[next])
			ret = max(ret, 1 + lis(next));

	return ret;
};
