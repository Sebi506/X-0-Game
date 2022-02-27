#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
	string symbol; //simbolul fiecarui jucator
    public:
	void setsymbol(string sym); //functie care seteaza simbolul fiecarui player
	string getsymbol();//functie care returneaza simbolul fiecarui player
};

