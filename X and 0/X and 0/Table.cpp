#include "Table.h"
#include <iostream>
#include <string>

using namespace std;

void Table::init()
{
	
	T[0][0] = "1";
	T[0][1] = "2";
	T[0][2] = "3";
	T[1][0] = "4";
	T[1][1] = "5";
	T[1][2] = "6";
	T[2][0] = "7";
	T[2][1] = "8";
	T[2][2] = "9";

}
void Table::printtable()
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << T[i][j];
			if (j < 2) cout << " | ";
			else cout << " ";
		}
		cout << endl;
		if (i < 2) cout << "---+---+---";
		cout << endl;
	}
}
int Table::valid_move(int position, int line, int column)
{
	if (position < 1) return 0;
	if (position > 9) return 0;
	if (T[line][column] == "X" || T[line][column] == "0") return 0;
	return 1;
}
int Table::add_move(int position, string symbol)
{
	int line, column;
	translate_move(position, line, column);
	if (valid_move(position, line, column) == 0) return 0;
	T[line][column] = symbol;
	return 1;
}
void Table::translate_move(int position, int& line, int& column)
{
	line = (position - 1) / 3;
	column = (position - 1) - (3 * ((position - 1) / 3));
}
int Table::check_win(int position, string symbol)
{
	int ok = 1, line, column;
	translate_move(position, line, column);
	for (int i = 0; i < 3; i++) //verif line
	{
		if (T[i][column] != symbol) ok = 0;
	}
	if (ok == 1) return 1;
	ok = 1;
	for (int i = 0; i < 3; i++) //verif column
	{
		if (T[line][i] != symbol) ok = 0;
	}
	if (ok == 1) return 1;
	ok = 1;
	if (line == column) //verif diag pr
	{
		for (int i = 0; i < 3; i++)
			if (T[i][i] != symbol) ok = 0;

		if (ok == 1) return 1;
		ok = 1;
	}
	if (line == (2 - column)) //verif diag sec
	{
		for (int i = 0; i < 3; i++)
			if (T[i][2 - i] != symbol) ok = 0;
		if (ok == 1) return 1;
	}
	return 0;
}
