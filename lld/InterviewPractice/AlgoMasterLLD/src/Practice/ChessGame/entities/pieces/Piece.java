package Practice.ChessGame.entities.pieces;

import Practice.ChessGame.entities.board.Board;
import Practice.ChessGame.entities.board.Cell;
import Practice.ChessGame.enums.Color;

public abstract class Piece {
    protected final Color color;
    // private int x,y;

    public Piece(Color color) {
        this.color = color;
    }

    public abstract boolean canMove(Board board, Cell from, Cell to);

    public Color getColor() {
        return color;
    }
}
