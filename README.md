
# Chess-SFML

Chess-SFML is a graphical chess game developed in C++ using the [Simple and Fast Multimedia Library (SFML)](https://www.sfml-dev.org/). This project provides an interactive chess game interface for two players to play locally, following standard chess rules.

## Features

- **Graphical User Interface (GUI):** 
  - Utilizes SFML to render a visually appealing chessboard and pieces.
- **Two-Player Mode:** 
  - Allows two users to play against each other on the same machine.
- **Standard Chess Rules:**
  - Implements chess rules, including piece-specific movements.

## Prerequisites

- **SFML Library:** 
  - The project requires the SFML library to be installed on your system. You can download it from the [official SFML website](https://www.sfml-dev.org/download.php).

## Compilation Instructions

### Windows (MinGW)

1. **Compile Source Files:**
   ```bash
   g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp -I <sfml-install-path>\include -mwindows
   ```

2. **Link Object Files:**
   ```bash
   g++ main.o board.o piece.o pieceTextures.o chessGame.o -mwindows -L <sfml-install-path>\lib -lsfml-graphics -lsfml-window -lsfml-system
   ```

3. **Runtime Dependencies:**
   - Ensure the following SFML runtime libraries are in the same directory as the executable:
     - `sfml-graphics-2.dll`
     - `sfml-system-2.dll`
     - `sfml-window-2.dll`

4. **Run the Application:**
   - Execute the generated `a.exe` file to start the game.

---

### Linux (GCC)

1. **Compile Source Files:**
   ```bash
   g++ -c main.cpp board.cpp piece.cpp pieceTextures.cpp chessGame.cpp
   ```

2. **Link Object Files:**
   ```bash
   g++ main.o board.o piece.o pieceTextures.o chessGame.o -lsfml-graphics -lsfml-window -lsfml-system
   ```

3. **Run the Application:**
   - Execute the `./a.out` file to start the game.

---

### Using CMake

1. **Generate Build Files:**
   ```bash
   mkdir build && cd build
   cmake ..
   ```

2. **Build the Project:**
   ```bash
   make
   ```

3. **Run the Application:**
   - Locate the executable in `build/src/Chess-SFML` and ensure it is placed alongside the `Textures` folder.

---

## How to Play

- **Piece Selection:** 
  - Click on any chess piece to select it.
- **Move Execution:** 
  - Click on a valid destination square to move the selected piece.
- **Game Rules:** 
  - The game enforces standard chess rules, including legal piece movements and captures.

---

## Demonstration Video

For a detailed demonstration of the Chess-SFML game, watch the video below:

[Chess-SFML Demonstration Video](https://drive.google.com/file/d/1skoAhiVAbu1QWPSLfpdAg4cP0dsUN3B-/view?usp=sharing)

---

## Project Structure

- **Source Files:**
  - `main.cpp`, `board.cpp`, `piece.cpp`, `pieceTextures.cpp`, `chessGame.cpp`
- **Textures:**
  - Images of chess pieces and the board are included in the `Textures` folder.
- **Styles:**
  - Custom styling for the board and pieces is handled programmatically.

---

## Credits

- **Piece Textures:** 
  - The chess piece textures are sourced from [OpenGameArt](https://opengameart.org/content/chess-pieces-and-board-squares).
- **SFML Library:** 
  - This project leverages the [SFML](https://www.sfml-dev.org/) library for graphics rendering and multimedia handling.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
