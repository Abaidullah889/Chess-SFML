Chess-SFML
Chess-SFML is a graphical chess game developed in C++ using the Simple and Fast Multimedia Library (SFML). It provides an interactive interface for two players to play chess on the same machine.

Features
Graphical User Interface (GUI): Utilizes SFML to render the chessboard and pieces, offering an intuitive visual experience.
Two-Player Mode: Allows two users to play against each other locally.
Standard Chess Rules: Implements the fundamental rules of chess, including valid moves for each piece.
Prerequisites
SFML Library: Ensure that SFML is installed on your system. You can download it from the official SFML website.
Compilation Instructions
Windows (MinGW)
Compile Source Files:

bash
Copy
Edit
g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp -I <sfml-install-path>\include -mwindows
Link Object Files:

bash
Copy
Edit
g++ main.o board.o piece.o pieceTextures.o chessGame.o -mwindows -L <sfml-install-path>\lib -lsfml-graphics -lsfml-window -lsfml-system
Runtime Dependencies:

Ensure that sfml-graphics-2.dll, sfml-system-2.dll, and sfml-window-2.dll are located in the same directory as the executable.

Run the Application:

Execute the generated a.exe to start the game.

Linux (GCC)
Compile Source Files:

bash
Copy
Edit
g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp
Link Object Files:

bash
Copy
Edit
g++ main.o board.o piece.o pieceTextures.o chessGame.o -lsfml-graphics -lsfml-window -lsfml-system
Run the Application:

Execute the generated ./a.out to start the game.

CMake
Generate Build Files:

bash
Copy
Edit
mkdir build && cd build
cmake ..
Build the Project:

bash
Copy
Edit
make
Run the Application:

The executable will be located in build/src/Chess-SFML. Ensure it is placed alongside the Textures folder before running.

How to Play
Piece Selection: Click on a piece to select it.
Move Execution: Click on a valid destination square to move the selected piece.
Game Rules: The game enforces standard chess rules, including legal moves for each piece.
Demonstration Video
For a visual demonstration of the game, you can watch the following video:

[Chess-SFML Demonstration Video](https://drive.google.com/file/d/1skoAhiVAbu1QWPSLfpdAg4cP0dsUN3B-/view?usp=sharing)

Credits
Piece Textures: The chess piece textures are sourced from OpenGameArt.
SFML Library: This project utilizes the SFML library for graphics rendering.
