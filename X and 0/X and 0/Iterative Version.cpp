/*#include <iostream>
#include <stdlib.h>
using namespace std;
char table[4][4]{ { '1','2','3'}, {'4' ,'5' ,'6'}, {'7' ,'8' ,'9' } };

void print_table()
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " ";
		for (int j = 0; j < 3; j++)
		{		cout << table[i][j];
		if (j < 2) cout << " | ";
		else cout << " ";
	}
		cout << endl;
		if (i < 2) cout << "---+---+---";
		cout << endl;
	}
}
void translate_position(int position,int &line,int &column)
{
    line =(position - 1) / 3;
	column = (position-1) - (3 * ((position - 1) / 3));
}
int check_win(int position,char symbol)
{
	int ok = 1,line,column;
	translate_position(position, line, column);
	for(int i=0;i<3;i++) //verif line
	{
		if (table[i][column] != symbol) ok = 0;
	}
	if (ok == 1) return 1;
	ok = 1;
	for (int i = 0; i < 3; i++) //verif column
	{
		if (table[line][i] != symbol) ok = 0;
	}
	if (ok == 1) return 1;
	ok = 1;
	if (line == column) //verif diag pr
	{
		for (int i = 0; i < 3; i++)
			if (table[i][i] != symbol) ok = 0;

		if (ok == 1) return 1;
		ok = 1;
	}
	if (line == (2 - column)) //verif diag sec
	{
		for (int i = 0; i < 3; i++)
			if (table[i][2 - i] != symbol) ok = 0;
		if (ok == 1) return 1;
	}
	return 0;
}
int validposition(int position)
{
	int line, column;
	if (position < 1) return 0;
	if (position > 9) return 0;
	translate_position(position, line, column);
	if (table[line][column] == 'X' || table[line][column] == '0') return 0;
	return 1;
}
int add_move(int position, char symbol)
{
	int line, column;
	if (!validposition(position)) return 0;
	translate_position(position, line, column);
	table[line][column] = symbol;
	return 1;
}
int play()
{
	int winner = 0, movecounter = 9, position, currentplayer = 1;
	char symbol;
	system("cls");
	print_table();
	while (winner == 0 && movecounter > 0)
	{
		if (currentplayer == 1) symbol = 'X';
		else symbol = '0';
		cout << "Jucator " << currentplayer << " alege pozitia : "; cin >> position;
		while (!add_move(position, symbol))
		{
			cout << "Jucator " << currentplayer << " alege o pozitie valida : "; cin >> position;
		}
		system("cls");
		print_table();
		if (check_win(position, symbol)==1) {cout << "Jucatorul " << currentplayer << " a castigat!"; return 0;}
		movecounter--;
		if (currentplayer == 1) currentplayer++;
		else currentplayer--;
	}
	if (winner == 0) cout << "Remiza";
	else cout << "Jucatorul " << currentplayer << " a castigat";
		return 0;
}
int main()
{  
    play();
	return 0;
}*/