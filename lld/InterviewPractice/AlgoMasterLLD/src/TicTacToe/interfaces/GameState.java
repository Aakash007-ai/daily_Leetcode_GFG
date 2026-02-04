package TicTacToe.interfaces;

import TicTacToe.Game;
import TicTacToe.customException.InvalidMoveException;
import TicTacToe.entities.Player;

public interface GameState {
    void handleMove(Game game, Player player, int row, int col) throws InvalidMoveException;
}
