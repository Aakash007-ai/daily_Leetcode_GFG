package Practice.ChessGame.entities.board;

import Practice.ChessGame.entities.pieces.Piece;

public class Cell {
    private int row,col;
    private Piece piece;
    
    public Cell(int row, int col) {
        this.row = row;
        this.col = col;
    }
    public boolean isOccupied(){
        return piece!= null;
    }
    public Piece getPiece() {
        return piece;
    }
    public void setPiece(Piece piece) {
        this.piece = piece;
    }

       public int getRow() {
        return row;
    }

    public void setRow(int row) {
        this.row = row;
    }

    public int getCol() {
        return col;
    }

    public void setCol(int col) {
        this.col = col;
    }

}
