so chess game

entites
Player,
Pawn, Bishop, Knight,King, Queen, Rook

Cell
Board
8x8 board

---

Board is of 2 color , same as Piece Color

so enum Color Black, White

each piece will have color, each cell also have color

Pieces have position, x,y or "A1", "A2", since each move in different way we prefer to choose x, y (eas in movement)

GameStatus
Idle, StaleCheckmate, Checkmate, Progress

we can also say game State but here state is fixed at a time in whole time, either progress, idle, check mate or ( as in future we can only check and put a check on gameStatus)

Player (color, name)
Piece (color, x,y)
enum Color Black,White

---
