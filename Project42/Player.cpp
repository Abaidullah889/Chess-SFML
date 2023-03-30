#include "Player.h"
#include"Header.h"
#include<string>
using namespace std;

Player::Player(string _n, Color _C)
{
	this->name = _n;
	this->C = _C;
}

string Player::getName()
{
	return this->name;
}

Color Player::getColor()
{
	return this->C;
}