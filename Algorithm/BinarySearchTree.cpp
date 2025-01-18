#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::Print_Inorder(Node* node)
{
	// 전위 순회 (preorder traverse)
	// 중위 순회 (inorder)
	// 후위 순회 (postorder)
	if (node == nullptr)
		return;

	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	// 재귀함수를 이용한 탐색방법

	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Search2(Node* node, int key)
{
	// 반복문을 이용한 탐색방법

	while (node && key != node->key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return node;
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)// 루트노드를 생성하는 경우
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)// 본인 자리 찾기
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	// 노드 구성
	newNode->parent = parent;

	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)// child가 없거나 오른쪽만 있는 경우
		Replace(node, node->right);

	else if (node->right == nullptr)// child가 왼쪽만 있는 경우
		Replace(node, node->left);

	else// child가 모두 있는 경우
	{
		// 다음 데이터 찾기
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

void BinarySearchTree::Replace(Node* u, Node* v)// u 서브트리를 v 서브트리로 교체
{
	if (u->parent == nullptr)
		_root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v)
		v->parent = u->parent;

	delete u;// u 서브트리 삭제
}
