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

	// 예시 1) 팀 동맹
	// users[1] <-> users[5]
	users[5].teamId = users[1].teamId; // 1

	// 예시 2) teamId==1인 팀과 teamId==2인 팀이 동맹
	for (User& user : users)
	{
		if (user.teamId == 1)
			user.teamId = 2;
	}

	// 찾기 연산 O(1)
	// 합치기 연산 O(N)

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

	void Merge(int u, int v)// u와 v를 합친다 (u가 v 밑으로)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		_parent[u] = v;
	}

	// 시간 복잡도 : 트리의 높이에 비례한 시간이 걸림
	// [1]		[3]
	// [2]	 [4][5]
	//			[0]

private:
	vector<int> _parent;
};

// 트리가 한쪽으로 기우는 문제 -> parent 재귀 설정 최적화
// 트리를 합칠 때, 항상 [높이가 낮은 트리를] [높이가 높은 트리] 밑으로 오게끔하는
// (Union-By-Rank) 랭크에 의한 합치기 최적화
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

		// 찾은 원소 루트에 대해서 트리높이 최적화 (경로압축)
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

		// rank[u] <= rank[v] 보장 (랭크기반 알고리즘)
		_parent[u] = v;

		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

	// 시간 복잡도 O(Ackermann(n)) = O(1)
	// [1]		[3]
	// [2]	 [4][5][0]

private:
	vector<int> _parent;
	vector<int> _rank;
};
