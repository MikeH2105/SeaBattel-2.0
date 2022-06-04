#include<conio.h>
#include<iostream>
#include"EmptyPole.h"
#include<windows.h>
#include "SeaBattel 2.0.h"
using namespace std;




class Player:public EmptyPole {
private:
	EmptyPole polePlayer;
public:
	void printPole(int x, int y)
	{
		cout << "Pole Player" << endl;
		polePlayer.printPole(x, y);
	}

};


class Bot :public EmptyPole {
private:
	EmptyPole poleBot;
public:
	
	void printPole(int x, int y) {
			cout << "Pole Bot" << endl;
			poleBot.printPole(x, y);
	}

};

int main()
{
	SetConsoleOutputCP(1251);
	Player player;
	Bot  bot;
	int x = 1; int y = 1, i = 0;
	char ch = 'X';
	cout << "ВІТАЄМО ВАС У ГРІ МОРСЬКИЙ БІЙ" << endl;
	cout << "Почати гру натисніть +" << endl;

	while (true) {
		char key = _getch();
		if (key == 'w') x--;
		if (key == 's') x++;
		if (key == 'a') y--;
		if (key == 'd') y++;
		if (x == 0 or x == 11 or y == 0 or y == 11) {//умова,за якої при виході за межі поля, змія повертається
			x = 2;
			y = 2;
		}
			
			if (key == '+') {
				cout << "Спочатку розтавимо кораблі нашого гравця:" << endl;
				bot.inputShips(x, y);
				cout << "Тепер дамо змогу розтавити кораблі компютеру" << endl;
				player.autoInputShips(x, y);
				cout << "Ну що до бою" << endl;
				while (true) {
					bot.autoShutOn(x, y);
					player.shutOn(x, y);
				}

			}

			cout << "Вийти з  гри натисніть -" << endl;
			if (key == '-') {
				break;

			}
			system("cls");

		
	}
}
