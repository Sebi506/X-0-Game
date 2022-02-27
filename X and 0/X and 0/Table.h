#pragma once
#include <iostream>
#include <string>

using namespace std;

class Table
{
	string T[4][4]; //tabelul sub forma de matrice de tip string
public : 
	void init();//functie care initializeaza tabelul
	void printtable();//functie care printeaza tabelul
	//void add_move(int line, int column, string symbol);
	int valid_move(int position,int line,int column);//functie care verifica daca o miscare data este valida respectiv poate fii realizata
	int add_move(int position,string symbol);//functie care adauga o miscare in tabel
	void translate_move(int position, int& line, int& column);//functie care returneaza linia si coloana unei pozitii din tabel ,notate de la 1 la 9
	int check_win(int position,string symbol); //functie care verifica daca s-au indeplinit conditiile de castig pentru unul din jucatori
};

