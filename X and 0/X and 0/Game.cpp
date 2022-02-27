#include <iostream>
#include <stdlib.h>
#include "Game.h"
#include "Player.h"
#include "Table.h"

using namespace std;

int Game::start() {
	int op;
	rules();
	set_symbols();
	t.init();
	play();
	cout << "Do you want to play again?" << endl;
		cout << "1.Yes"<<endl;
	    cout << "2.No"<<endl;
		cout << "Option : "; cin >> op;
		while(op<1 || op>2)
		{
			system("cls");
			t.printtable();
			cout << "Do you want to play again?" << endl<<endl;
			cout << "1.Yes" << endl;
			cout << "2.No"<<endl;
			cout << "Option : "; cin >> op;
		}
		if (op == 1) start(); 
		return 0;
}
void Game::set_symbols()
{
	int op;
	system("cls");
	cout << "Player 1 ,choose your symbol.Player 2 will get the other one."<<endl<<endl;
	cout << "1.X"<<endl;
	cout << "2.O" << endl;
	cout << "Option : "; cin >> op;
	while (op < 1 || op>2)
	{
		system("cls");
		cout << "Player 1 ,choose your symbol.Player 2 will get the other one." << endl << endl;
		cout << "1.X" << endl;
		cout << "2.O" << endl;
		cout << "Option : "; cin >> op;
	}
	if (op == 1) { p[0].setsymbol("X"); p[1].setsymbol("0"); }
	else { p[0].setsymbol("0"); p[1].setsymbol("X");}
}
void Game::rules()
{
	int op;
	system("cls");
	cout << "            Welcome to X & 0" << endl << endl<<endl;
	cout << " How to play :"<<endl<<endl;
	cout << "  Players will choose one position at a time from the table(from 1 to 9)" << endl;
	cout << "where they will place their assigned symbol.";
	cout << "The first player to form a straight line of their symbol(vertically,horizontally or oblique) in the table,wins." << endl;
	cout << "Otherwise,the match will end as a draw."<<endl<<endl;
	cout << "1.Next" << endl;
	cout << "Option : "; cin >> op;
	if (op != 1) rules();
}
int Game::play()
{
	int op, nrmoves = 9, winner = 0, currentplayer = 1;
	string s;
	while (winner == 0 && nrmoves > 0)
	{

	system("cls");

	t.printtable();

	cout << "Player " << currentplayer << " choose a position for your symbol :"; cin >> op;

	while (!t.add_move(op, p[currentplayer-1].getsymbol()))
	{
		system("cls");
		t.printtable();
		cout << "Player " << currentplayer << " choose a valdi position for your symbol :"; cin >> op;
	}
	if (t.check_win(op, p[currentplayer - 1].getsymbol()) == 1) winner = currentplayer; 
	else
	{
		if (currentplayer == 1) currentplayer++;
		else currentplayer--;
		nrmoves--;
	}
	}
	system("cls");
	t.printtable();
	if(winner!=0) cout << endl << "Player " << currentplayer << " won" << endl << endl;
	else cout << endl << "Draw" << endl << endl;
	return 0;
}
int main()
{
	Game g;
	g.start();
	return 0;
}
