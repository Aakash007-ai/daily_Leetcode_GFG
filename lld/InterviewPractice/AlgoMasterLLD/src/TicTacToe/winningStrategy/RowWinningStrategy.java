package TicTacToe.winningStrategy;

import TicTacToe.entities.Board;
import TicTacToe.entities.Player;
import TicTacToe.interfaces.WinningStrategy;

public class RowWinningStrategy implements WinningStrategy {

    @Override
    public boolean checkWinner(Board board, Player player) {
        for(int row = 0;row< board.getSize(); row++){
            boolean rowwin = true;
            for(int col=0;col<board.getSize(); col++){
                if(board.getCell(row, col).getSymbol() != player.getSymbol()){
                    rowwin = false;
                    break;
                }
            }
            if(rowwin) return true;
        }
        return false;
    }

}
