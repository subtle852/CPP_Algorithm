#include <iostream>
#include <vector>
#include "MyVector.h"
#include <list>
#include "MyList.h"
#include <stack>
#include "MyStack.h"
#include <queue>
#include "MyQueue.h"
#include "CreateGraph.h"
//#include "Dfs.h"
//#include "Bfs.h"
#include "Dijkstra.h"
using namespace std;


int main()
{
	#pragma region vector 구현
	{
		////vector<int> v;
		//MyVector<int> v;

		//v.reserve(100);
		//cout << v.size() << " " << v.capacity() << endl;

		//for (int i = 0; i < 100; i++)
		//{
		//	v.push_back(i);
		//	cout << v.size() << " " << v.capacity() << endl;
		//}

		//v.resize(10);
		//cout << v.size() << " " << v.capacity() << endl;

		//v.clear();
		//cout << v.size() << " " << v.capacity() << endl;
	}
	#pragma endregion

	#pragma region list 구현
	{
		////list<int> li;
		//MyList<int> li;

		//MyList<int>::iterator eraseIt;

		//for (int i = 0; i < 10; i++)
		//{
		//	if (i == 5)
		//	{
		//		eraseIt = li.insert(li.end(), i);
		//	}
		//	else
		//	{
		//		li.push_back(i);
		//	}
		//}

		//li.pop_back();

		//li.erase(eraseIt);

		//for (MyList<int>::iterator it = li.begin(); it != li.end(); it++)
		//{
		//	cout << (*it) << endl;
		//}
	}
	#pragma endregion

	#pragma region stack 구현
	{
		////stack<int> s;
		////stack<int, deque<int>> s;
		////stack<int, vector<int>> s;
		////stack<int, list<int>> s;
		//MyStack<int, list<int>> s;

		//// 삽입
		//s.push(1);
		//s.push(2);
		//s.push(3);

		//while (s.empty() == false)
		//{
		//	// 최상위 원소 삭제
		//	int data = s.top();
		//	s.pop();

		//	cout << data << endl;
		//}

		//int size = s.size();
	}
	#pragma endregion

	#pragma region queue 구현
	{
		////queue<int> q;
		//MyVectorQueue<int> q;
		////MyListQueue<int> q;

		//for (int i = 0; i < 100; i++)
		//	q.push(i);

		//while (q.empty() == false)
		//{
		//	int value = q.front();
		//	q.pop();
		//	cout << value << endl;
		//}

		//int size = q.size();
	}
	#pragma endregion

	#pragma region 그래프 구현
	{
		//CreateGraph::CreateGraph_Struct();
		//CreateGraph::CreateGraph_AdjacencyList();
		//CreateGraph::CreateGraph_AdjacencyMatrix();
	}
	#pragma endregion

	#pragma region DFS
	{
		//// [인접리스트 버전]
		////CreateGraph_AdjacencyList();

		//// 하나의 정점만 실행
		////visited = vector<bool>(6, false);
		////Dfs_AdjacencyList(0);

		//// 모든 정점 실행 (트리가 아닌 단방향 그래프이기에)
		////DfsAll_AdjacencyList();

		////////////////////////////////////////////////////
		//// [인접행렬 버전]
		//CreateGraph_AdjacencyMatrix();
		//DfsAll_AdjacencyMatrix();
	}
	#pragma endregion

	#pragma region BFS
	{
		// [인접리스트 버전]
		//CreateGraph_AdjacencyList();

		//discovered = vector<bool>(6, false);

		//Bfs_AdjacencyList(0);
		//BfsAll_AdjacencyList();


		////////////////////////////////////////////////////
		//// [인접행렬 버전]
		//CreateGraph_AdjacencyMatrix();

		//discovered = vector<bool>(6, false);

		//Bfs_AdjacencyMatrix(0);
		//BfsAll_AdjacencyMatrix();

	}
	#pragma endregion
	
#pragma region Dijkstra
	{
		CreateGraph();
		Dijkstra(0);
	}
#pragma endregion

}