#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph_AdjacencyList()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	// ���� ����Ʈ
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
}

void CreateGraph_AdjacencyMatrix()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	// ���� ���
	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0},
		{ 1, 0, 1, 1, 0, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
		{ 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0},
	};
}

void Dfs_AdjacencyList(int here)
{
	// �湮
	visited[here] = true;
	cout << "Visited : " << here << endl;

	// ��� ���� ������ ��ȸ
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];

		// ���� �湮���� ���� ���� ������ �湮
		if (visited[there] == false)
			Dfs_AdjacencyList(there);
	}
}

void Dfs_AdjacencyMatrix(int here)
{
	// �湮
	visited[here] = true;
	cout << "Visited : " << here << endl;

	// ��� ���� ������ ��ȸ
	for (int there = 0; there < 6; there++)
	{
		// ������� ���� ���� �ɷ�����
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ������ �湮
		if (visited[there] == false)
			Dfs_AdjacencyMatrix(there);
	}
}

void DfsAll_AdjacencyList()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
		{
			Dfs_AdjacencyList(i);
		}
	}
}

void DfsAll_AdjacencyMatrix()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
		{
			Dfs_AdjacencyMatrix(i);
		}
	}
}


