#pragma once
#include <vector>
using namespace std;

void Example()
{
	struct User
	{
		int teamId;
		// TODO
	};

	// TODO : UserManager
	vector<User> users;
	for (int i = 0; i < 1000; i++)
	{
		users.push_back(User{ i });
	}

	// ���� 1) �� ����
	// users[1] <-> users[5]
	users[5].teamId = users[1].teamId; // 1

	// ���� 2) teamId==1�� ���� teamId==2�� ���� ����
	for (User& user : users)
	{
		if (user.teamId == 1)
			user.teamId = 2;
	}

	// ã�� ���� O(1)
	// ��ġ�� ���� O(N)

}

class NaiveDisjointSet
{
public:
	NaiveDisjointSet(int n) : _parent(n)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		return Find(_parent[u]);
	}

	void Merge(int u, int v)// u�� v�� ��ģ�� (u�� v ������)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		_parent[u] = v;
	}

	// �ð� ���⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�
	// [1]		[3]
	// [2]	 [4][5]
	//			[0]

private:
	vector<int> _parent;
};

// Ʈ���� �������� ���� ���� -> parent ��� ���� ����ȭ
// Ʈ���� ��ĥ ��, �׻� [���̰� ���� Ʈ����] [���̰� ���� Ʈ��] ������ ���Բ��ϴ�
// (Union-By-Rank) ��ũ�� ���� ��ġ�� ����ȭ
class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		//_parent[u] = Find(_parent[u]);
		//return _parent[u];

		// ã�� ���� ��Ʈ�� ���ؼ� Ʈ������ ����ȭ (��ξ���)
		return _parent[u] = Find(_parent[u]);
	}

	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] ���� (��ũ��� �˰���)
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

	// �ð� ���⵵ O(Ackermann(n)) = O(1)
	// [1]		[3]
	// [2]	 [4][5][0]

private:
	vector<int> _parent;
	vector<int> _rank;
};
