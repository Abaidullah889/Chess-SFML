#include "King.h"
#include"Header.h"
#include"Piece_Texture.h"
#include<iostream>

using namespace std;

King::King(int ri, int ci, Color C, Board* _b):Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();
	isFirstMove = true;
	sprite.setTexture(((this->C == white) ? Piece_Texture::whiteKing : Piece_Texture::blackKing));
	sprite.setScale(sf::Vector2f(0.245f, 0.245f));
	sprite.setPosition((71 * ci + 6), (71 * ri + 7));
}
void King::Draw()
{
	cout << ((C == white) ? "K" : "k");
}
bool King::isLegal(Board* b, int sr, int sc, int dr, int dc)
{
	int Dr = abs(dr - sr);
	int Dc = abs(dc - sc);

	if (IsDiagonal(sr, sc, dr, dc) && Dc==1)
	{
		return true;
	}
	if (IsVertical(sr, sc, dr, dc) && Dr == 1)
	{
		return true;
	}
	if (IsHorizontal(sr, sc, dr, dc) && Dc == 1)
	{
		return true;
	}
	return false;
}
void King::setMove()
{
	isFirstMove = false;
}
char King::getSym()
{
	return this->sym;
}
void King::setSprite(int r, int c)
{
	sprite.setPosition((71 * c + 6), (71 * r + 7));
}
sf::Sprite King::getSpirit()
{
	return sprite;
}
bool King::getMove()
{
	return isFirstMove;
}