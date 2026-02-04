package TicTacToe.gameState;

import TicTacToe.Game;
import TicTacToe.customException.InvalidMoveException;
import TicTacToe.entities.Player;
import TicTacToe.interfaces.GameState;

public class DrawState implements GameState {
    @Override
    public void handleMove(Game game, Player player, int row, int col) throws InvalidMoveException {
        throw new InvalidMoveException("Game is already over. It was a draw.");
    }
}
