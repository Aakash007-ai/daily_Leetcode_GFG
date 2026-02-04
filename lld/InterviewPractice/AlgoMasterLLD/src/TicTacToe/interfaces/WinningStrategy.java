package TicTacToe.interfaces;

import TicTacToe.entities.Board;
import TicTacToe.entities.Player;

public interface WinningStrategy {
    boolean checkWinner(Board board, Player player);
}
