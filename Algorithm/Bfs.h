#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//vector<Vertex> vertices;// DFS에 선언된 부분으로 사용
//vector<vector<int>> adjacent;// DFS에 선언된 부분으로 사용
vector<bool> discovered;

//void CreateGraph_AdjacencyList()// DFS에 선언된 부분으로 사용
//void CreateGraph_AdjacencyMatrix()// DFS에 선언된 부분으로 사용

void Bfs_AdjacencyList(int here)
{
	// 누구에 의해 발견 되었는지?
	vector<int> parent(6, -1);
	// 시작점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited: " << here << " Parent: " << parent[here] << " Distance: " << distance[here] << endl;

		for (int i = 0; i < adjacent[here].size(); i++)// for (int there : adjacent[here])// 가능
		{
			int there = adjacent[here][i];

			if (discovered[there] == true)
				continue;

			q.push(there);
			discovered[there] = true;
			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}
}

void Bfs_AdjacencyMatrix(int here)
{
	// 누구에 의해 발견 되었는지?
	vector<int> parent(6, -1);
	// 시작점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false)
	{
		here = q.front();
		q.pop();

		cout << "Visited: " << here << " Parent: " << parent[here] << " Distance: " << distance[here] << endl;

		for (int i = 0; i < 6; i++)
		{
			if (adjacent[here][i] == 0)
				continue;

			if (discovered[i] == true)
				continue;

			q.push(i);
			discovered[i] = true;
			parent[i] = here;
			distance[i] = distance[here] + 1;
		}
	}
}

void BfsAll_AdjacencyList()
{
	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			Bfs_AdjacencyList(i);
}

void BfsAll_AdjacencyMatrix()
{
	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			Bfs_AdjacencyMatrix(i);
}