⚓ Battleship Game in C

A console-based Battleship game implemented in C where two players compete by placing ships and firing at each other's grid.

🛠 Features
Two-player gameplay
Ship placement with validation
Hit / Miss tracking
Ship destruction notifications
Game loop until one player wins
💻 Technologies
C Programming Language
Console-based application
📖 Description

This game simulates the classic Battleship game. Players place ships on a 20x20 grid and take turns attacking each other's board. The game continues until all ships of one player are sunk.

🎮 How to Play
1️⃣ Compile the Program

Open a terminal in the project folder and run:

gcc battleship.c -o battleship

Replace battleship.c with your file name if different.

2️⃣ Run the Game
./battleship
3️⃣ Ship Placement

Players place ships one by one. For each ship, enter:

Row (0–19)
Column (0–19)
Orientation:
0 = horizontal
1 = vertical

Example:

Row: 3
Column: 5
Orientation (0=horizontal, 1=vertical): 0
4️⃣ Gameplay
Players take turns entering coordinates to fire at the opponent’s grid.
Hits, misses, and ship destruction are displayed in the console.

Example Turn:

Player 1's turn. Enter row and column to fire: 5 7
HIT!
🏆 Winning

The game ends when all ships of one player are sunk:

Player 2 wins!
📂 Project Structure
battleship-game-c/
├── battleship.c      # Main C program
├── README.md         # Project documentation
