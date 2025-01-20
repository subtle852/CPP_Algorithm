#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>

// '테이블' 개념 O(1)
void TestTable()
{
	struct User
	{
		int userId = 0; // 1~999
		string username;
	};

	vector<User> users;
	users.resize(1000);

	// 777번 유저 정보 세팅
	users[777] = User{ 777, "Chovy" };

	// 777번 유저 이름은?
	string name = users[777].username;
	cout << name << endl;
}

// '해시' 개념
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
	int key = (userId % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key] = User{ userId, "Chovy" };

	// 123456789번 유저 이름은?
	User& user = users[key];
	if (user.userId == userId)
	{
		string name = user.username;
		cout << name << endl;
	}
}

// 충돌 문제를 해결하는 체이닝
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
	int key = (userId % 1000); // hash < 고유번호

	// 123456789번 유저 정보 세팅
	users[key].push_back(User{ userId, "Chovy" });
	users[789].push_back(User{ 789, "Faker" });

	// 123456789번 유저 이름은?
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
