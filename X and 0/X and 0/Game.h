#pragma once
#include <iostream>
#include "Player.h"
#include "Table.h"

using namespace std;

class Game
{
	Player p[2];
	Table t;
public:
	int start(); //functie care incepe procesul jocului respectiv regulile,setarea de simboluri si jocul in sine
	void set_symbols(); //functie care seteaza simbolurile jucatorilor
	void rules(); //functie care afiseaza regulile
	int play();//functie care incepe o runda a jocului
};

