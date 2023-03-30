#include "Board.h"
#include"Piece.h"
#include"Pawn.h"
#include"Rook.h"
#include"Bishop.h"
#include"Cell.h"
#include"King.h"
#include"Knight.h"
#include"Header.h"
#include"Queen.h"
#include"Cell.h"
#include<iostream>
#include<fstream>
using namespace std;

#define row 8
#define col 8

Board::Board()
{
	this->C = nullptr;
}
Board::Board(Board* B)
{
	C = new Cell * *[8];

	for (int r = 0; r < 8; r++)
	{
		C[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			this->C[r][c] = new Cell(*(B->C[r][c]));
			this->C[r][c]->setpc(B->C[r][c]->getpc());
		}
	}
}
void Board::writer(ofstream& wtr,char***&mb,int &nb)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->C[i][j]->getpc() != nullptr)
			{
				switch (this->C[i][j]->getpc()->getSym())
				{
				case'p':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'p': wtr << 'P');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'p' : mb[nb][i][j] = 'P');
					break;
				case'r':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'r' : wtr << 'R');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'r' : mb[nb][i][j] = 'R');
					break;
				case'k':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'k' : wtr << 'K');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'k' : mb[nb][i][j] = 'K');
					break;
				case'q':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'q' : wtr << 'Q');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'q' : mb[nb][i][j] = 'Q');
					break;
				case'n':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'n' : wtr << 'N');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'n' : mb[nb][i][j] = 'N');
					break;
				case'b':
					((C[i][j]->getpc()->getColor() == black) ? wtr << 'b' : wtr << 'B');
					((C[i][j]->getpc()->getColor() == black) ? mb[nb][i][j] = 'b' : mb[nb][i][j] = 'B');
					break;
				default:
					wtr << '-';
					mb[nb][i][j] = '-';
					break;
				}
			}
			else
			{
				mb[nb][i][j] = '-';
				wtr << '-';
			}
			
		}
		wtr << endl;
	}
	nb++;

}
void Board::setBoard(char** B)
{
	this->C = new Cell * *[8];
	for (int r = 0; r < 8; r++)
	{
		C[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			switch (B[r][c])
			{
			case 'n':
				this->C[r][c] = new Cell(r, c, new Knight(r, c, black, this));
				break;
			case 'k':
				this->C[r][c] = new Cell(r, c, new King(r, c, black, this));
				break;
			case 'r':
				this->C[r][c] = new Cell(r, c, new Rook(r, c, black, this));
				break;
			case 'b':
				this->C[r][c] = new Cell(r, c, new Bishop(r, c, black, this));
				break;
			case 'p':
				this->C[r][c] = new Cell(r, c, new Pawn(r, c, black, this));
				if (r != 1)
				{
					C[r][c]->getpc()->setMove();
				}
				break;
			case 'q':
				this->C[r][c] = new Cell(r, c, new Queen(r, c, black, this));
				break;
			case 'N':
				this->C[r][c] = new Cell(r, c, new Knight(r, c, white, this));
				break;
			case 'K':
				this->C[r][c] = new Cell(r, c, new King(r, c, white, this));
				break;
			case 'R':
				this->C[r][c] = new Cell(r, c, new Rook(r, c, white, this));
				break;
			case 'B':
				this->C[r][c] = new Cell(r, c, new Bishop(r, c, white, this));
				break;
			case 'P':
				this->C[r][c] = new Cell(r, c, new Pawn(r, c, white, this));
				if (r != 6)
				{
					C[r][c]->getpc()->setMove();
				}
				break;
			case 'Q':
				this->C[r][c] = new Cell(r, c, new Queen(r, c, white, this));
				break;
			case'-':
				this->C[r][c] = new Cell(r, c, nullptr);
				break;
			}
		}
	}
}
Board::Board(ifstream& rdr)
{
	char cs[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			rdr >> cs[i][j];
		}
	}

	this->C = new Cell * *[8];
	for (int r = 0; r < 8; r++)
	{
		C[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			switch (cs[r][c])
			{
			case 'n':
				this->C[r][c] = new Cell(r, c, new Knight(r, c, black, this));
				break;
			case 'k':
				this->C[r][c] = new Cell(r, c, new King(r, c, black, this));
				break;
			case 'r':
				this->C[r][c] = new Cell(r, c, new Rook(r, c, black, this));
				break;
			case 'b':
				this->C[r][c] = new Cell(r, c, new Bishop(r, c, black, this));
				break;
			case 'p':
				this->C[r][c] = new Cell(r, c, new Pawn(r, c, black, this));
				if (r != 1)
				{
					C[r][c]->getpc()->setMove();
				}
				break;
			case 'q':
				this->C[r][c] = new Cell(r, c, new Queen(r, c, black, this));
				break;
			case 'N':
				this->C[r][c] = new Cell(r, c, new Knight(r, c, white, this));
				break;
			case 'K':
				this->C[r][c] = new Cell(r, c, new King(r, c, white, this));
				break;
			case 'R':
				this->C[r][c] = new Cell(r, c, new Rook(r, c, white, this));
				break;
			case 'B':
				this->C[r][c] = new Cell(r, c, new Bishop(r, c, white, this));
				break;
			case 'P':
				this->C[r][c] = new Cell(r, c, new Pawn(r, c, white, this));
				if (r != 6)
				{
					C[r][c]->getpc()->setMove();
				}
				break;
			case 'Q':
				this->C[r][c] = new Cell(r, c, new Queen(r, c, white, this));
				break;
			case'-':
				this->C[r][c] = new Cell(r, c, nullptr);
				break;
			}
		}
	}

}
void Board::displayBoard(sf::RenderWindow* window)
{
	/*system("cls");
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < col; c++)
		{
			if ( (c%2==0 && r%2==0)  || (c % 2 != 0 && r % 2 != 0))
			{
				SetClr(15,0);
			}
			else
			{
				SetClr(8,15);
			}
			this->C[r][c]->draw(r,c,8,8);
		}
		cout << endl;
	}*/


	sf::Event event;
	while (window->isOpen())
	{
		/*while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			}

		}*/
		/*window->clear(sf::Color::Black);
		for (int r = 0; r < 8; r++)
		{
			for (int c = 0; c < col; c++)
			{
				window->draw(C[r][c]->square);
				C[r][c]->getpc()->setTexture(r,c);
				window->draw(C[r][c]->getpc()->getSpirit());
			}
		}
		window->display();*/
	}

	

}
void Board::Move(int sr, int sc, int dr, int dc)
{
	//Ps[dr][dc] = Ps[sr][sc];
	//Ps[sr][sc] = nullptr;

	this->C[dr][dc]->setpc(this->C[sr][sc]->getpc());
	this->C[sr][sc]->setpc(nullptr);
}
bool Board::isLegalMove(Board*, int sr, int sc, int dr, int dc)
{
	Piece* P = this->C[sr][sc]->getpc();

	if (P != nullptr)
		return (this->C[sr][sc]->getpc())->isLegal(this,sr, sc, dr, dc);
}
Piece* Board::getPiece(int r, int c)
{
	return C[r][c]->getpc();
}
Cell* Board::getCell(int r, int c)
{
	return C[r][c];

}
void Board::updateBoard(int sr, int sc, int dr, int dc)
{
	if ((sr + sc) % 2 == 0)
	{
		SetClr(15, 15);
		this->C[sr][sc]->draw(sr, sc, 8, 8);
	}
	else
	{
		SetClr(8, 15);
		this->C[sr][sc]->draw(sr, sc, 8, 8);
	}

	if ((dr + dc) % 2 == 0)
	{
		SetClr(15, 0);
		this->C[dr][dc]->draw(dr, dc, 8, 8);
	}
	else
	{
		SetClr(8, 15);
		this->C[dr][dc]->draw(dr, dc, 8, 8);
	}
	
}

