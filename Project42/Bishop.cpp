#include "Bishop.h"
#include"Header.h"
#include"Piece_Texture.h"
#include<iostream>
using namespace std;

Bishop::Bishop(int ri, int ci, Color C, Board* _b) :Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();

	sprite.setTexture(((this->C == white) ? Piece_Texture::whiteBishop : Piece_Texture::blackBishop));
	sprite.setScale(sf::Vector2f(sf::Vector2f(0.245f, 0.245f)));
	sprite.setPosition((71 * ci + 6), (71 * ri + 7));
}
void Bishop::Draw()
{
	cout << ((C == white) ? "B" : "b");
}
bool Bishop::isLegal(Board* b, int sr, int sc, int dr, int dc)
{
	return (IsDiagonal(sr,sc, dr,dc) && IsDiagonalPathClear(b, sr, sc, dr, dc));
}
void Bishop::setMove()
{
	isFirstMove = false;
}
char Bishop::getSym()
{
	return this->sym;
}
void Bishop::setSprite(int r, int c)
{
	sprite.setPosition((71 * c + 6), (71 * r + 7));

}
sf::Sprite Bishop::getSpirit()
{
	return sprite;
}
bool Bishop::getMove()
{
	return isFirstMove;
}