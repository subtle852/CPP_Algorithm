#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>

// '���̺�' ���� O(1)
void TestTable()
{
	struct User
	{
		int userId = 0; // 1~999
		string username;
	};

	vector<User> users;
	users.resize(1000);

	// 777�� ���� ���� ����
	users[777] = User{ 777, "Chovy" };

	// 777�� ���� �̸���?
	string name = users[777].username;
	cout << name << endl;
}

// '�ؽ�' ����
void TestHash()
{
	struct User
	{
		int userId = 0; // 1~int32_max
		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key] = User{ userId, "Chovy" };

	// 123456789�� ���� �̸���?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}
}

// �浹 ������ �ذ��ϴ� ü�̴�
void TestHashTableChaining()
{
	struct User
	{
		int userId = 0; // 1~int32_max
		string username;
	};

	vector<vector<User>> users;
	users.resize(1000);

	const int userId = 123456789;
	int key = (userId % 1000); // hash < ������ȣ

	// 123456789�� ���� ���� ����
	users[key].push_back(User{ userId, "Chovy" });
	users[789].push_back(User{ 789, "Faker" });

	// 123456789�� ���� �̸���?
	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userId == userId)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}
