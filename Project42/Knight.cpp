#include "Knight.h"
#include"Header.h"
#include"Piece_Texture.h"
#include<iostream>



using namespace std;

Knight::Knight(int ri, int ci, Color C, Board* _b) :Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();

	sprite.setTexture(((this->C == white) ? Piece_Texture::whiteKnight : Piece_Texture::blackKnight));
	sprite.setScale(sf::Vector2f(0.245f, 0.245f));
	sprite.setPosition((71 * ci + 6), (71 * ri + 6));
}
void Knight::Draw()
{
	cout << ((C == white) ? "N" : "n");
}
bool Knight::isLegal(Board* b, int sr, int sc, int dr, int dc)
{
	int C = dc - sc;
	int R = dr - sr;

	if (R == -2 && (C == -1 || C == 1))
	{
		return true;
	}
	else if (R == 2 && (C == 1 || C == -1))
	{
		return true;
	}
	else if (C == 2 && (R == 1 || R == -1))
	{
		return true;
	}
	else if (C == -2 && (R == 1 || R == -1))
	{
		return true;
	}
	return false;
}
void Knight::setMove()
{
	isFirstMove = false;
}
char Knight::getSym()
{
	return this->sym;
}
void Knight::setSprite(int r, int c)
{
	sprite.setPosition((71 * c + 6), (71 * r + 6));
}
sf::Sprite Knight::getSpirit()
{
	return sprite;
}
bool Knight::getMove()
{
	return isFirstMove;
}