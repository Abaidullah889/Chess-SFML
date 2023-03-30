#pragma once

#include"Header.h"
#include"Board.h"
class Board;

//struct Position
//{
//	int ri, ci;
//};

class Piece
{
protected:
	int row;
	int col;
	char t;
	Color C;
	Board*B;
	bool IsHorizontal(int sr, int sc, int dr, int dc)
	{
		return (sr == dr);
	}
	bool IsVertical(int sr, int sc, int dr, int dc)
	{
		return (sc == dc);

	}
	bool IsDiagonal(int sr, int sc, int dr, int dc)
	{
		int Dr = abs(sr - dr);
		int Dc = abs(sc - dc);

		return Dr == Dc;
	}
	bool IsHorizontalPathClear(Board* b, int sr, int sc, int dr, int dc)
	{
		int cs, ce;
		if (sc < dc)
		{
			cs = sc + 1;
			ce = dc - 1;
		}
		else
		{
			cs = dc + 1;
			ce = sc - 1;
		}
		for (int i = cs; i <= ce; i++)
		{
			if (b->getPiece(sr, i) != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	bool IsVerticalPathClear(Board* b, int sr, int sc, int dr, int dc)
	{
		if (sr < dr)
		{
			for (int i = sr + 1; i < dr; i++)
			{
				if (b->getPiece(i, sc) != nullptr)
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = sr - 1; i > dr; i--)
			{
				if (b->getPiece(i, sc) != nullptr)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool IsDiagonalL2R(Board* b, int sr, int sc, int dr, int dc)
	{
		if (sr < dr)
		{
			int Dr = dr - sr;

			for (int i = 1; i < Dr; i++)
			{
				if (b->getPiece(sr + i, sc + i) != nullptr)
					return false;
			}
			return true;
		}
		else
		{
			int Dr = sr - dr;

			for (int i = 1; i < Dr; i++)
			{
				if (b->getPiece(sr - i, sc - i) != nullptr)
					return false;
			}
			return true;
		}

	}
	bool IsDiagonalR2L(Board* b, int sr, int sc, int dr, int dc)
	{

		if (sr < dr)
		{
			int Dr = dr - sr;
			for (int i = 1; i < Dr; i++)
			{
				if (b->getPiece(sr + i, sc - i) != nullptr)
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			int Dr = sr - dr;
			for (int i = 1; i < Dr; i++)
			{
				if (b->getPiece(sr - i, sc + i) != nullptr)
				{
					return false;
				}
			}
			return true;
		}
	}
	bool IsDiagonalPathClear(Board* b, int sr, int sc, int dr, int dc)
	{
		int Dr = sr - dr;
		int Dc = sc - dc;

		if (Dr == Dc)
		{
			return IsDiagonalL2R(b, sr, sc, dr, dc);
		}
		return IsDiagonalR2L(b, sr, sc, dr, dc);

	}

public:
	Piece(int row, int col, Color C, Board* _b);
	virtual void Draw() = 0;
    virtual bool isLegal(Board*,int, int, int, int) = 0;
	void Move(int row, int col);
	virtual void setMove()=0;
	virtual char getSym() = 0;
	virtual sf::Sprite getSpirit() = 0;
	virtual void setSprite(int r, int c) = 0;
	virtual bool getMove() = 0;
	Color getColor();

};

