#pragma once
#include"Piece.h"

class Rook:public Piece
{
private:
	bool isFirstMove;
	char sym = 'r';
public:
	Rook(int ri, int ci, Color C, Board* _b);
	virtual void Draw();
	virtual bool isLegal(Board* b, int sr, int sc, int dr, int dc);
	virtual void setMove();
	virtual char getSym();
	sf::Sprite sprite;
	virtual void setSprite(int r, int c);
	virtual sf::Sprite getSpirit();
	virtual bool getMove();
};

