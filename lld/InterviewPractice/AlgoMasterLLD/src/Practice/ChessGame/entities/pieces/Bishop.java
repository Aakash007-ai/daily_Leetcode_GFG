package Practice.ChessGame.entities.pieces;

import Practice.ChessGame.entities.board.Board;
import Practice.ChessGame.entities.board.Cell;
import Practice.ChessGame.enums.Color;

public class Bishop extends Piece {
    public Bishop(Color color) {
        super(color);
    }

    @Override
    public boolean canMove(Board board, Cell from, Cell to) {
        int rowDiff = Math.abs(to.getRow() - from.getRow());
        int colDiff = Math.abs(to.getCol() - from.getCol());
        return (rowDiff == colDiff);
    }
}
