#include "Cell.h"
#include "Board.h"
#include"Header.h"
#include"Piece.h"
#include"Pawn.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Queen.h"
#include<Windows.h>
#include<iostream>
using namespace std;

 

Cell::Cell(int ri, int ci, Piece* Pi)
{
	r = ri;
	c = ci;
	P = Pi;
	square = sf::Sprite();
	square.setTexture(((this->r + this->c) % 2 == 0) ? Piece_Texture::Square1 : Piece_Texture::Square2);
	square.setScale(sf::Vector2f(0.275f, 0.275f));
	square.setPosition(c * 71, r * 71);
}
void Cell::draw(int sr, int sc,int rdim,int cdim)
{
	//char sym = -37;
	//for (int r = 0; r < rdim; r++)
	//{
	//	for (int c = 0; c < cdim; c++)
	//	{
	//		/*if (r == 0 || c == 0 || r == rdim - 1 || c == cdim - 1)
	//		{
	//			gotoRowCol(sr + r, sc + c);
	//			cout << sym;
	//		}
	//		else
	//		{
	//			gotoRowCol(sr + r, sc + c);
	//			cout << "  ";
	//		}*/
	//		if (r == rdim / 2 && c == cdim / 2)
	//		{
	//			gotoRowCol((sr*8) + r, (sc*8) + c);
	//			if (this->P == nullptr)
	//			{
	//				cout << '-';
	//			}
	//			else
	//			{
	//				P->Draw();
	//			}
	//		}
	//		else
	//		{
	//			gotoRowCol((sr * 8) + r, (sc * 8) + c);
	//			cout << sym;
	//		}
	//	}
	//}

	
}
void Cell::setpc(Piece* DP)
{
	/*if (DP != nullptr)
	{
		delete[]P;
		this->P = DP;
	}
	else
	{
		this->P = DP;
	}*/

	this->P = DP;
	
}
Piece* Cell::getpc()
{
	return this->P;
}