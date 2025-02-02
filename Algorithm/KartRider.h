#pragma once
#include <iostream>
#include <vector>
using namespace std;

// ����
// īƮ�� ������ �����ϸ� �޸��� �����ϸ�, �־��� �ð�(T)���� �޸���.
// īƮ�� ó������ �⺻ �ӵ� (�ʼ� 1)�� �޸���.
// ������ �����ϰ� Ư�� �ð�(a)�� �Ǹ� �ٴڿ� �Ź� �������� �����ȴ�.
// īƮ�� �Ź��� �Űų� ����ĥ �� �ִ�. ������ �Ź��� �ٽ� ���� �� ����.
// �Ź��� �����Ϸ��� (b)�� �ð��� �ʿ��ϴ�. �� (b)�� ���� ���ڸ����� ���߰� ������ ������ �� �ִ�.
// �Ź��� �����ϸ� �����ð�(c) ���� �Ź� �ӵ�(d)�� �޸� �� �ִ�.
// �Ź��� �ϳ��� ������ �� �ְ�, ���� �ֱٿ� ������ �Ź��� �ӵ��� ����ȴ�. 
// �Ź��� ���ų� �ٸ� �Ź߷� �ٲ� ������ ���� �߰��ð��� ���� �ʴ´�. (���ο� �Ź��� �Ŵ� �ð��� �ҿ� �ȴ�)
// �Ź� ȿ���� ������ �ٽ� �⺻ �ӵ� (�ʼ� 1)�� �޸���.

// ����
// �����Ǵ� ��� �Ź� ������ �־����� ��, (T)�� ���� �� �� �ִ� �ִ� �Ÿ��� ���϶�.

struct Shoe
{
	Shoe(int a, int b, int c, int d)
	{
		time = a;
		start = a + b;
		end = a + b + c;
		speed = d;
	}

	int time; // a (�Ź� ���� �ð�)
	int start; // a+b (�Ź� ȿ�� ���� �ð�)
	int end; // a+b+c (�Ź� ȿ�� ������ �ð�)
	int speed; // d (�Ź� �ӵ�)
};

int T;
vector<Shoe> shoes;
vector<int> cache;

// input.txt
// 20
// 4
// 3 4 10 3
// 4 1 4 2
// 10 2 5 5
// 15 1 3 7

// now�� �Ź��� �Ű� �� �� �ִ� �ִ� �Ÿ��� ��ȯ
int Solve(int now)
{
	// ���� ���
	if (now >= shoes.size())
		return 0;

	// ĳ��
	int& ret = cache[now];
	if (ret != -1)
		return ret;

	// ����
	Shoe& shoe = shoes[now];

	// �Ź� �Ű� �̵��� �Ÿ� + �ɾ �̵��� �Ÿ�
	int dist = (shoe.end - shoe.start) * shoe.speed + (T - shoe.end) * 1;
	ret = max(ret, dist);

	// �ٸ� �Źߵ� �ϳ��� �ž��
	for (int next = now + 1; next < shoes.size(); next++)
	{
		Shoe& nextShoe = shoes[next];
		if (nextShoe.time < shoe.start)
			continue;

		// ���� �Ź߱��� �̵� �Ÿ�
		int moveDist = 0;

		// ���� �Ź� ȿ���� ������ ���� ���� �Ź��� ���� ��
		if (nextShoe.time <= shoe.end)
		{
			moveDist = (nextShoe.time - shoe.start) * shoe.speed; // �Ź� �Ű� �̵�
		}
		else
		{
			moveDist = (shoe.end - shoe.start) * shoe.speed; // �Ź� �Ű� �̵�
			moveDist += (nextShoe.time - shoe.end) * 1; // ������ �κ� �ɾ �̵�
		}

		ret = max(ret, moveDist + Solve(next));
	}

	return ret;
}
