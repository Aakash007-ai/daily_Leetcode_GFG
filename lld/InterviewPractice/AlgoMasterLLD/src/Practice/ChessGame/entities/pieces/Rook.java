package Practice.ChessGame.entities.pieces;

import Practice.ChessGame.entities.board.Board;
import Practice.ChessGame.entities.board.Cell;
import Practice.ChessGame.enums.Color;

public class Rook extends Piece {
    public Rook(Color color) {
        super(color);
    }

    @Override
    public boolean canMove(Board board, Cell from, Cell to) {
        return (from.getRow() == to.getRow() || from.getCol() == to.getCol());
    }
}
