#pragma once
#include"Header.h"
class Board;
class Piece;
class Player;

class Chess
{
	int sr, sc, dr, dc;
	int Turn;
	Player* Ps[2];
	Board* B;
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

public:
	Chess();
	void displayTurnMsg(Player*P);
	void selectPiece(int &r,int & c, sf::RenderWindow* W);
	void selectDestination();
	bool validSourceSelection(Player*P,int r, int c, Board* B);
	bool validDestination(Player*P, int dr, int dc, Board* B);
	void turnChange();
	void hBOX(int sri, int sci, int rdim, int cdim, char sym);
	void unhBOX(int sr, int sc, int rdim, int cdim, int cols);
	bool** CompHigh(Board* B, int sri, int sci, Player** p, int turn);
	void Highlight(Board* B, int sri, int sci, bool** b, int turn);
	void unHighlight(Board* B, int sri, int sci, bool** b, int turn);
	void findKing(Board* B, Player* p, int& Kr, int& Kc);
	bool Check(Board* b, Player** p, int turn);
	bool selfCheck(Board* B, int sci, int sri, int dci, int dri, Player** p, int turn);
	bool selfCheck1(Board* B, int sci, int sri, int dci, int dri, Player** p, int turn);
	bool CanIMove(Board* B, Player** p, int turn);
	bool StaleMate(Board* B, int Turn,Player** P);
	void Promotion(Board* B, int sr, int sc, int dr, int dc, Player** P, int Turn);
	void Save(Board* B);
	bool Castling(Board* B, int sr, int sc, int dr, int dc, int& tr, int& tc);
	void Play();
	~Chess();


	////////////////////////////////////////////////////////////Public Parameters//////////////////////////////////////////////////////////////////

	char*** mb;
	int bn;
	int t_b;
	bool* cb;
	int Ws;
	int Bs;
	int wdelay;
	int bdelay;
};

