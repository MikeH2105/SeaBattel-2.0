#pragma once
class EmptyPole{
protected:
	int n;
	int m;
	char** matrix = nullptr;
	int count;
	int enemycount;


public:
	EmptyPole();//����� ��������� ������� ����
	void printPole(int x, int y);//����� ��������� ���� �� �����
	void shutOn(int x, int y);
	void inputShips(int x, int y);
	void autoInputShips(int x, int y);
	void autoShutOn(int x, int y);
};

