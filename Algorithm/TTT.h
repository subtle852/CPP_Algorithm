#pragma once

int HashKey(const vector<vector<char>>& board)
{
	int ret = 0;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			ret = ret * 3;

			if (board[y][x] == 'o')
				ret += 1;
			else if (board[y][x] == 'x')
				ret += 2;
		}
	}

	return ret;
}

vector<vector<char>> board;
int cache[19683];

bool IsFinished(const vector<vector<char>>& board, char turn)
{
	// �¿�
	for (int i = 0; i < 3; i++)
		if (board[i][0] == turn && board[i][1] == turn && board[i][2] == turn)
			return true;

	// ����
	for (int i = 0; i < 3; i++)
		if (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn)
			return true;

	// �밢��
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
		return true;

	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn)
		return true;

	return false;
}

enum
{
	DEFAULT = 2,
	WIN = 1,
	DRAW = 0,
	LOSE = -1
};

int CanWin(vector<vector<char>>& board, char turn)
{
	// ���� ���
	if (IsFinished(board, 'o' + 'x' - turn))
		return LOSE;

	// ĳ�� Ȯ��
	int key = HashKey(board);
	int& ret = cache[key];
	if (ret != DEFAULT)
		return ret;

	// ����

	// [.][x][.]
	// [.][o][.]
	// [.][.][.]
	int minValue = DEFAULT;

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (board[y][x] != '.')
				continue;

			// �ڸ��� �ֱ�
			board[y][x] = turn;

			// Ȯ��
			minValue = min(minValue, CanWin(board, 'o' + 'x' - turn)); // ������ �й��ϴ°� ���� ���� ���̽�

			// �ڸ��� ���� (�ʱ�ȭ)
			board[y][x] = '.';
		}
	}

	if (minValue == DRAW || minValue == DEFAULT)
		return ret = DRAW;

	return ret = -minValue;
}
