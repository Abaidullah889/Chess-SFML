#include "Pawn.h"
#include"Header.h"
#include"Piece_Texture.h"
#include"Cell.h"
#include"Board.h"
#include<iostream>

using namespace std;

Pawn::Pawn(int ri, int ci, Color C, Board* _b) :Piece(ri, ci, C, _b)
{
	sprite = sf::Sprite();
	sprite.setTexture(((this->C == white) ? Piece_Texture::whitePawn : Piece_Texture::blackPawn));
	sprite.setScale(sf::Vector2f(0.245f, 0.245f));
	sprite.setPosition((71 * ci+11), (71 * ri+7));
	isFirstMove = true;
}
void Pawn::Draw()
{
	cout << ((C == white) ? "P" : "p");
}
bool Pawn::isLegal(Board *b,int sr,int sc,int dr,int dc)
{

	int C_ = abs(sc - dc);
	int R = abs(sr - dr);

	//int C = dc - sc;
	//int R = dr - sr;


	if (isFirstMove == true)
	{
		if (b->C[dr][dc]->getpc() == nullptr)
		{
			if (R == 2 || R == 1)
			{
				if ((C == white) && sr > dr)
				{
					return((IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b,sr, sc, dr, dc)));
				}
				if ((C == black && sr < dr))
				{
					return((IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b, sr, sc, dr, dc)));
				}
			}
		}
		else if ((C != b->C[dr][dc]->getpc()->getColor()) && (b->C[dr][dc]->getpc() != nullptr))
		{
			if (C == white && sr-dr==1)
			{
				//return ((IsDiagonal(sr, sc, dr, dc) && (IsDiagonalL2R(b, sr, sc, dr, dc) || IsDiagonalR2L(b, sr, sc, dr, dc))));
				return ((IsDiagonal(sr, sc, dr, dc) && IsDiagonalPathClear(b, sr, sc, dr, dc)));
			}
			if (C == black && dr - sr == 1)
			{
				return ((IsDiagonal(sr, sc, dr, dc) && IsDiagonalPathClear(b,sr,sc,dr,dc)));
				//return ((IsDiagonal(sr, sc, dr, dc) && (IsDiagonalL2R(b, sr, sc, dr, dc) || IsDiagonalR2L(b, sr, sc, dr, dc))));

			}
		}
	}
	else
	{
		if (b->C[dr][dc]->getpc() == nullptr)
		{
			if (R == 1)
			{
				if ((C == white) && sr > dr)
				{
					return((IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b, sr, sc, dr, dc)));
				}
				if ((C == black && sr < dr))
				{
					return((IsVertical(sr, sc, dr, dc) && IsVerticalPathClear(b, sr, sc, dr, dc)));
				}
			}
		}
		else if ((C != b->C[dr][dc]->getpc()->getColor()) && (b->C[dr][dc]->getpc() != nullptr))
		{
			if (C == white && sr - dr == 1)
			{
				//return ((IsDiagonal(sr, sc, dr, dc) &&(IsDiagonalL2R(b, sr, sc, dr, dc) || IsDiagonalR2L(b, sr, sc, dr, dc))));
				return ((IsDiagonal(sr, sc, dr, dc) && IsDiagonalPathClear(b, sr, sc, dr, dc)));
			}
			else if (C == black && dr - sr == 1)
			{
				//return ((IsDiagonal(sr, sc, dr, dc) && (IsDiagonalL2R(b, sr, sc, dr, dc) || IsDiagonalR2L(b, sr, sc, dr, dc))));
				return ((IsDiagonal(sr, sc, dr, dc) && IsDiagonalPathClear(b, sr, sc, dr, dc)));
			}
		}
	}
	return false;

	//if (isFirstMove == true)
	//{
	//	if (this->C == white)
	//	{
	//		return ((R == -2 || R== -1) && (C == 0));
	//		/*if (R == -2 && (C == 0) == true)
	//		{
	//			isFirstMove = false;
	//			return true;
	//		}
	//		else
	//		{
	//			isFirstMove = true;
	//			return false;
	//		}*/
	//	}
	//	else if (this->C == black)
	//	{
	//		return ((R == 2 || R==1)&& (C == 0));
	//		/*if (R == 2 && (C == 0) == true)
	//		{
	//			isFirstMove = false;
	//			return true;
	//		}
	//		else
	//		{
	//			isFirstMove = true;
	//			return false;
	//		}*/
	//	}
	//}
	//else
	//{
	//	if (this->C == white)
	//	{
	//		if (b->getPiece(sr - 1, sc) != nullptr)
	//		{
	//			if (sc - 1 >= 0)
	//			{
	//				if (b->getPiece(sr - 1, sc - 1) != nullptr)
	//				{
	//					return (R == -1 && (C == -1));
	//				}
	//			}
	//			else if (sc + 1 < 8)
	//			{
	//				if (b->getPiece(sr - 1, sc + 1) != nullptr)
	//				{
	//					return (R == -1 && (C == 1));
	//				}
	//			}
	//			return false;
	//		}
	//		else if (b->getPiece(sr - 1, sc) == nullptr)
	//		{
	//			if (sc + 1<8)
	//			{
	//				if (b->getPiece(sr - 1, sc + 1) != nullptr && b->getPiece(sr - 1, sc) == nullptr)
	//				{
	//					return (R == -1 && (C == +1)) || (R == -1 && (C == 0));
	//				}
	//				else if (b->getPiece(sr - 1, sc + 1) != nullptr && b->getPiece(sr - 1, sc) != nullptr)
	//				{
	//					return (R == -1 && (C == +1));
	//				}
	//			}
	//			else if (sc - 1 >= 0)
	//			{
	//				if (B->getPiece(sr - 1, sc - 1) != nullptr && b->getPiece(sr - 1, sc) == nullptr)
	//				{
	//					return (R == -1 && (C == -1)) || (R == -1 && (C == 0));
	//				}
	//				if (B->getPiece(sr - 1, sc - 1) != nullptr && b->getPiece(sr - 1, sc) != nullptr)
	//				{
	//					return (R == -1 && (C == -1));
	//				}
	//			}
	//			return (R == -1 && (C == 0));
	//		}
	//	}
	//	else if (this->C == black)
	//	{
	//		if (b->getPiece(sr + 1, sc) != nullptr)
	//		{
	//			if (sc + 1 < 8)
	//			{
	//				if (b->getPiece(sr + 1, sc + 1) != nullptr)
	//				{
	//					return (R == 1 && (C == 1));
	//				}
	//			}
	//			else if (sc - 1 >= 0)
	//			{
	//				if (b->getPiece(sr + 1, sc - 1) != nullptr)
	//				{
	//					return (R == 1 && (C == -1));
	//				}
	//			}
	//			return false;
	//		}
	//		else if (b->getPiece(sr + 1, sc) == nullptr)
	//		{
	//			if (sc + 1 < 8)
	//			{
	//				if (b->getPiece(sr + 1, sc + 1) != nullptr && b->getPiece(sr + 1, sc) == nullptr)
	//				{
	//					return (R == 1 && (C == 1)) || (R == 1 && (C == 0));
	//				}
	//				else if (b->getPiece(sr + 1, sc + 1) != nullptr && b->getPiece(sr + 1, sc) != nullptr)
	//				{
	//					return (R == 1 && (C == 1));
	//				}
	//			}
	//			else if (sc - 1 >= 0)
	//			{
	//				if (b->getPiece(sr + 1, sc - 1) != nullptr && b->getPiece(sr + 1, sc) == nullptr)
	//				{
	//					return (R == 1 && (C == -1)) || (R == 1 && (C == 0));
	//				}
	//				else if (b->getPiece(sr + 1, sc - 1) != nullptr && b->getPiece(sr + 1, sc) != nullptr)
	//				{
	//					return (R == 1 && (C == -1));
	//				}
	//			}
	//			return (R == 1 && (C == 0));
	//		}
	//	}
	//}
	
}
void Pawn::setMove()
{
	isFirstMove=false;
}
char Pawn::getSym()
{
	return this->sym;
}
void Pawn::setSprite(int r, int c)
{
	sprite.setPosition((71 * c + 11), (71 * r + 7));
}
sf::Sprite Pawn::getSpirit()
{
	return sprite;
}
bool Pawn::getMove()
{
	return isFirstMove;
}