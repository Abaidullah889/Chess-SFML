#include "Queen.h"
#include"Header.h"
#include"Piece_Texture.h"
#include<iostream>
using namespace std;



Queen::Queen(int ri, int ci, Color C, Board* _b) :Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();

	sprite.setTexture(((this->C == white) ? Piece_Texture::whiteQueen : Piece_Texture::blackQueen));
	sprite.setScale(sf::Vector2f(0.245f, 0.245f));
	sprite.setPosition((71 * ci + 3), (71 * ri + 7));
}
void Queen::Draw()
{
	cout << ((C == white) ? "Q" : "q");
}
bool Queen::isLegal(Board* b, int sr, int sc, int dr, int dc)
{
	int Dr = abs(dr - sr);
	int Dc = abs(dc - sc);

	if (IsDiagonal(sr, sc, dr, dc) && IsDiagonalPathClear(b, sr, sc, dr, dc))
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
	if (((IsHorizontal(sr, sc, dr, dc) && IsHorizontalPathClear(b, sr, sc, dr, dc)) || (IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b, sr, sc, dr, dc))))
	{
		return true;
	}
	return false;
}
void Queen::setMove()
{
	isFirstMove = false;
}
char Queen::getSym()
{
	return this->sym;
}
void Queen::setSprite(int r,int c)
{
	sprite.setPosition((71 * c + 3), (71 * r + 7));
}
sf::Sprite Queen::getSpirit()
{
	return sprite;
}
bool Queen::getMove()
{
	return isFirstMove;
}
