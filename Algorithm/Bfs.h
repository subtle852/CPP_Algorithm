#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//vector<Vertex> vertices;// DFS�� ����� �κ����� ���
//vector<vector<int>> adjacent;// DFS�� ����� �κ����� ���
vector<bool> discovered;

//void CreateGraph_AdjacencyList()// DFS�� ����� �κ����� ���
//void CreateGraph_AdjacencyMatrix()// DFS�� ����� �κ����� ���

void Bfs_AdjacencyList(int here)
{
	// ������ ���� �߰� �Ǿ�����?
	vector<int> parent(6, -1);
	// ���������� ��ŭ ������ �ִ���?
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

		for (int i = 0; i < adjacent[here].size(); i++)// for (int there : adjacent[here])// ����
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
	// ������ ���� �߰� �Ǿ�����?
	vector<int> parent(6, -1);
	// ���������� ��ŭ ������ �ִ���?
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