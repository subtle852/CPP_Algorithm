#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // 인접 행렬

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

void Dijkstra(int here)
{
	// 초기 설정
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;// 발견 목록
	vector<int> best(6, INT32_MAX);// 각 정점별로 지금까지 발견한 최소 거리
	vector<int> parent(6, -1);// 경로저장을 위한 부모

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = here;

	// list 빌 때까지 반복
	while (discovered.empty() == false)
	{
		// 1. 제일 좋은 후보를 찾는다
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); it++)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		// 2. erase
		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		// 3. 위를 통해 찾은 후보가 best보다 큰 경우는 필요없음
		if (best[here] < cost)
			continue;

		// 4. 방문
		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않은 경우 제외
			if (adjacent[here][there] == -1)
				continue;

			// 더 좋은 경로를 과거에 찾았으면 제외
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there, nextCost });// 발견한 것들을 다 넣어주는 방식
			best[there] = nextCost;
			parent[there] = here;
		}
	}

	int a = 3;
}