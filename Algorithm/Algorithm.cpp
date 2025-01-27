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
//#include "Dijkstra.h"
//#include "Tree.h"
#include "MyPriorityQueue.h"
#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include <thread>
#include "BasicSort.h"
#include "EfficientSort.h"
#include "QuickSort.h"
#include "HashTable.h"
//#include "DisjointSet.h"
#include "Kruskal.h"
#include <windows.h>
#include <functional>
#include "DPIntro.h"
#include "LIS.h"
#include "TrianglePath.h"
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
		//CreateGraph();
		//Dijkstra(0);
	}
	#pragma endregion

	#pragma region Tree
	{
		//NodeRef root = CreateTree();

		//PrintTree(root, 0);

		//int height = GetHeight(root);
		//cout << "Tree Height : " << height << endl;
	}
	#pragma endregion

	#pragma region priority queue 구현
	{
		//MyPriorityQueue<int, vector<int>, greater<int>> pq;

		//pq.push(100);
		//pq.push(300);
		//pq.push(200);
		//pq.push(500);
		//pq.push(400);

		//while (pq.empty() == false)
		//{
		//	int value = pq.top();
		//	pq.pop();

		//	cout << value << endl;
		//}

	}
	#pragma endregion

	#pragma region 이진 탐색 구현
	{
		//numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
		//BinarySearch(81);

	}
	#pragma endregion

	#pragma region 이진탐색트리 구현
	{
		//BinarySearchTree bst;

		//bst.Insert(30);
		//bst.Insert(10);
		//bst.Insert(20);
		//bst.Insert(25);
		//bst.Insert(26);
		//bst.Insert(40);
		//bst.Insert(50);

		//bst.Delete(20);
		//bst.Delete(26);

		//bst.Print();
	}
	#pragma endregion

	#pragma region 레드블랙트리 구현
	{
		//BinarySearchTree bst;

		//bst.Insert(30);
		//bst.Print();
		//this_thread::sleep_for(1s);

		//bst.Insert(10);
		//bst.Print();
		//this_thread::sleep_for(1s);

		//bst.Insert(20);
		//bst.Print();
		//this_thread::sleep_for(1s);

		//bst.Insert(25);
		//bst.Print();
		//this_thread::sleep_for(1s);

		//bst.Delete(20);
		//bst.Print();
		//this_thread::sleep_for(1s);

		//bst.Delete(10);
		//bst.Print();
		//this_thread::sleep_for(1s);
	}
	#pragma endregion

	#pragma region 버블, 선택, 삽입정렬 구현
	{
		//vector<int> v{ 1, 5, 3, 4, 2 };

		//std::sort(v.begin(), v.end());

		////BubbleSort(v);
		////SelectionSort(v);
		//InsertionSort(v);
	}
	#pragma endregion

	#pragma region 힙, 병합, 퀵소트 구현
	{
		//vector<int> v;

		//srand(time(0));

		//for (int i = 0; i < 50; i++)
		//{
		//	int randValue = rand() % 100;
		//	v.push_back(randValue);
		//}

		////HeapSort(v);
		////MergeSort(v, 0, v.size() - 1);

		//QuickSort(v, 0, v.size() - 1);

		//int a = 0;
	}
	#pragma endregion

	#pragma region 해시테이블
	{
		//TestTable();
		////TestHash();
	}
	#pragma endregion

	#pragma region Disjoint Set
	{
		//DisjointSet teams(1000);

		//teams.Merge(10, 1);
		//int teamId = teams.Find(1);
		//int teamId2 = teams.Find(10);

		//teams.Merge(3, 2);
		//int teamId3 = teams.Find(3);
		//int teamId4 = teams.Find(2);

		//teams.Merge(1, 3);
		//int teamId6 = teams.Find(1);
		//int teamId7 = teams.Find(3);
	}
	#pragma endregion

	#pragma region Kruskal
	{
		//CreateGraph_Kruskal();

		//vector<CostEdge> selected;
		//int cost = Kruskal(selected);

	}
	#pragma endregion

	#pragma region DP 입문
	{
		//// Combination 재귀
		//__int64 start = GetTickCount64();
		//int lotto = combination(45, 6);
		//__int64 end = GetTickCount64();
		//cout << end - start << " ms" << endl;

		//// Combination 재귀 + memoization
		//::memset(CombinationCache, -1, sizeof(CombinationCache));
		//start = GetTickCount64();
		//lotto = combination_memo(45, 6);
		//end = GetTickCount64();
		//cout << end - start << " ms" << endl;

	}
	#pragma endregion

	#pragma region LIS
	{
		//::memset(LisCache, -1, sizeof(LisCache));
		//seq = vector<int>{ 10, 1, 9, 2, 5, 7 };

		//int ret = 0;
		//for (int pos = 0; pos < seq.size(); pos++)
		//	ret = max(ret, lis(pos));

		//cout << "LIS: " << ret << endl;
	}
	#pragma endregion

	#pragma region TRIANGLE PATH
	{
		board = vector<vector<int>>
		{
			{6},
			{1, 2},
			{3, 7, 4},
			{9, 4, 1, 7},
			{2, 7, 5, 9, 4}
		};

		N = board.size();
		cache = vector<vector<int>>(N, vector<int>(N, -1));
		nextX = vector<vector<int>>(N, vector<int>(N));

		int ret = path(0, 0);
		cout << ret << endl;

		// 경로 만들기
		int y = 0;
		int x = 0;

		while (y < N)
		{
			cout << board[y][x] << " -> ";

			x = nextX[y][x];
			y++;
		}

	}
	#pragma endregion

}