#include "Piece_Texture.h"
#include"Header.h"
#include<string>
#include<iostream>
using namespace std;

sf::Texture Piece_Texture::blackKing = Piece_Texture::loadTexture("Textures/b_king.png");
sf::Texture Piece_Texture::blackQueen = Piece_Texture::loadTexture("Textures/b_queen.png");
sf::Texture Piece_Texture::blackRook = Piece_Texture::loadTexture("Textures/b_rook.png");
sf::Texture Piece_Texture::blackKnight = Piece_Texture::loadTexture("Textures/b_knight.png");
sf::Texture Piece_Texture::blackBishop = Piece_Texture::loadTexture("Textures/b_bishop.png");
sf::Texture Piece_Texture::blackPawn = Piece_Texture::loadTexture("Textures/b_pawn.png");
sf::Texture Piece_Texture::whiteKing = Piece_Texture::loadTexture("Textures/w_king.png");
sf::Texture Piece_Texture::whiteQueen = Piece_Texture::loadTexture("Textures/w_queen.png");
sf::Texture Piece_Texture::whiteRook = Piece_Texture::loadTexture("Textures/w_rook.png");
sf::Texture Piece_Texture::whiteKnight = Piece_Texture::loadTexture("Textures/w_knight.png");
sf::Texture Piece_Texture::whiteBishop = Piece_Texture::loadTexture("Textures/w_bishop.png");
sf::Texture Piece_Texture::whitePawn = Piece_Texture::loadTexture("Textures/w_pawn.png");
sf::Texture Piece_Texture::Red = Piece_Texture::loadTexture("Textures/Red.png");
sf::Texture Piece_Texture::Green = Piece_Texture::loadTexture("Textures/Green.png");
sf::Texture Piece_Texture::Square1 = Piece_Texture::loadTexture("Textures/square_gray_dark.png");
sf::Texture Piece_Texture::Square2 = Piece_Texture::loadTexture("Textures/square_gray_light.png");
sf::Texture Piece_Texture::BackGround = Piece_Texture::loadTexture("Textures/Background.png");
sf::Font Piece_Texture::font2 = Piece_Texture::loadFont("Textures/font2.ttf");
sf::Texture Piece_Texture::Undo = Piece_Texture::loadTexture("Textures/Undo.png");
sf::Texture Piece_Texture::Redo = Piece_Texture::loadTexture("Textures/Redo.png");
sf::Texture Piece_Texture::loadTexture(string str) 
{
    sf::Texture tmp;
    if (!tmp.loadFromFile(str))
         cout << "Error loading file\n";
    return tmp;
}
sf::Font Piece_Texture::loadFont(string str)
{
    sf::Font tempf;
    if (!tempf.loadFromFile(str))
        cout << "Error loading file\n";
    return tempf;

}