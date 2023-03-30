#pragma once
#include"Header.h"
#include<string>
using namespace std;

class Player
{
	string name;
	Color C;

public:
	Player(string _n, Color _C);
	string getName();
	Color getColor();
};

