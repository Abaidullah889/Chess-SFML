#include "Rook.h"
#include"Header.h"
#include<iostream>
using namespace std;



Rook::Rook(int ri, int ci, Color C, Board* _b) :Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();
	isFirstMove = true;
	sprite.setTexture(((this->C == white) ? Piece_Texture::whiteRook : Piece_Texture::blackRook));
	sprite.setScale(sf::Vector2f(0.245f, 0.245f));
	sprite.setPosition((71 * ci + 9), (71 * ri + 7));
}
void Rook::Draw()
{
	//cout << ((C == white) ? "R" : "r");
	//sprite.setPosition(73 *, 73)
}
bool Rook::isLegal(Board* b, int sr, int sc, int dr, int dc)
{
	return ((IsHorizontal(sr,sc, dr,dc) && IsHorizontalPathClear(b, sr, sc, dr, dc)) || (IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b, sr, sc, dr, dc)));
}
char Rook::getSym()
{
	return this->sym;
}
void Rook::setMove()
{
	isFirstMove = false;
}
void Rook::setSprite(int r, int c)
{
	sprite.setPosition((71 * c + 9), (71 * r + 7));
}
sf::Sprite Rook::getSpirit()
{
	return sprite;
}
bool Rook::getMove()
{
	return isFirstMove;
}

