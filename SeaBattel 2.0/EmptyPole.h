#pragma once
class EmptyPole{
protected:
	int n;
	int m;
	char** matrix = nullptr;
	int count;
	int enemycount;


public:
	EmptyPole();//метод створення пустого поля
	void printPole(int x, int y);//метод виведення поля на екран
	void shutOn(int x, int y);
	void inputShips(int x, int y);
	void autoInputShips(int x, int y);
	void autoShutOn(int x, int y);
};

