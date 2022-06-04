#include "EmptyPole.h"
#include<conio.h>
#include<iostream>
#include <cmath>
using namespace std;

EmptyPole::EmptyPole() 
{
	n = 11;
	m = 11;
	matrix = new char* [n];
	char arr[11]{ '-','1', '2', '3','4','5','6','7','8','9','10'};
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new char[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			this->matrix[i][0] = arr[i];
			this->matrix[0][j] = arr[j];
			matrix[i][j] = '-';
		}
	}
}
void EmptyPole::printPole(int x, int y) {
		
		matrix[x][y] = '*';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "  ";
				cout << matrix[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[x][y] == '*') {
					matrix[x][y] = '-';
				}
			}
			cout << endl;
		}

}

void EmptyPole::shutOn(int x, int y){
	cout << "Введіть координати Х та У пострілу:" << endl;
	cin >> x;
	cin >> y;
	if (matrix[x][y] == '@') 
	{
		if (count == 20)
		{
			cout << "Перемога за гравцем!!!!!!!!!!!!!!" << endl;
			cout << "ВІТАЄМО" << endl;
			
		}
		count++;
		matrix[x][y] = 'X';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "  ";
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		matrix[x][y] = 'O';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "  ";
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	cout << "Кількість влучень: "<<count << endl;

}


void EmptyPole::inputShips(int x, int y){
	for (int i = 0; i < 4; i++)
	{
		cout << "Введіть координати Х та У для встановлення чотирьох однопалубних  кораблів:" << endl;
		cin >> x;
		cin >> y;
		matrix[x][y] = '#';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				cout << "  ";
				cout << matrix[i][j];

			}
			cout << endl;
			
		}

	}


	int hor = 0;
	for (int i = 0; i < 3; i++)
	{	cout << "Введіть координати Х та У для встановлення трьох двопалубних  кораблів по горизонталі:" << endl;
		cin >> x;
		cin >> y;
		cout << "Введіть розположення корабля 1-по вертикалі або 0 по горизонталі" << endl;
		cin >> hor;
		if (hor == 1) {
			matrix[x][y] = '#';
			matrix[x + 1][y] = '#';
		}
		else {

			matrix[x][y] = '#';
			matrix[x][y + 1] = '#';
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{

					cout << "  ";
					cout << matrix[i][j];

				}
				cout << endl;
			}
			
		}
	}



	for (int i = 0; i < 2; i++)
	{
		cout << "Введіть координати Х та У для встановлення двох трипалубних  кораблів по горизонталі:" << endl;
		cin >> x;
		cin >> y;
		cout << "Введіть розположення корабля 1-по вертикалі або 0 по горизонталі" << endl;
		cin >> hor;
		if (hor == 1) {
			matrix[x][y] = '#';
			matrix[x + 1][y] = '#';
			matrix[x + 2][y] = '#';
		}
		else {

			matrix[x][y] = '#';
			matrix[x][y + 1] = '#';
			matrix[x][y + 2] = '#';
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{

					cout << "  ";
					cout << matrix[i][j];

				}
				cout << endl;
			}

		}
	}


	cout << "Введіть координати Х та У для встановлення чотирипалубного  корабля по горизонталі:" << endl;
	cin >> x;
	cin >> y;
	cout << "Введіть розположення корабля 1-по вертикалі або 0 по горизонталі" << endl;
	cin >> hor;
	if (hor == 1) {
		matrix[x][y] = '#';
		matrix[x + 1][y] = '#';
		matrix[x + 2][y] = '#';
		matrix[x + 3][y] = '#';
	}
	else {

		matrix[x][y] = '#';
		matrix[x][y + 1] = '#';
		matrix[x][y + 2] = '#';
		matrix[x][y + 3] = '#';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				cout << "  ";
				cout << matrix[i][j];

			}
			cout << endl;
		}

	}
}





void EmptyPole::autoInputShips(int x, int y)
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {

		x = abs(1 + rand() % 10);
		y = abs(1 + rand() % 10);
		matrix[x][y] = '@';
	}


	int hor = 1;
	for (int i = 0; i < 3; i++)
	{
		x = abs(1+rand() % 10);
		y = abs(1 + rand() % 10);
	
			matrix[x][y] = '@';
			matrix[x][y + 1] = '@';
	}



	for (int i = 0; i < 2; i++)
	{
		x = abs(1 + rand() % 10);
		y = abs(1 + rand() % 10);
			matrix[x][y] = '@';
			matrix[x][y + 1] = '@';
			matrix[x][y + 2] = '@';
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{

					cout << "  ";
					cout << matrix[i][j];

				}
				cout << endl;
			}

		
	}

	for (int i = 0; i < 3; i++)
	{
		x = abs(1 + rand() % 10);
		y = abs(1 + rand() % 10);
		matrix[x][y] = '@';
		matrix[x][y + 1] = '@';
		matrix[x][y + 2] = '@';
		matrix[x][y + 3] = '@';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				cout << "  ";
				cout << matrix[i][j];

			}
			cout << endl;
		}


	}
}

void EmptyPole::autoShutOn(int x, int y)
{
	x= abs(1 + rand() % 10);
	y= abs(1 + rand() % 10);
	if (matrix[x][y] == '#')
	{
		enemycount++;
		matrix[x][y] = 'X';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "  ";
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		matrix[x][y] = 'O';
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << "  ";
				cout << matrix[i][j];
			}
			cout << endl;
		}
	}
	cout << "Кількість влучень: " << enemycount << endl;

}

