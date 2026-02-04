package Practice.SnakeAndLadder;

import java.lang.module.ModuleDescriptor.Builder;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import Practice.SnakeAndLadder.entities.Board;
import Practice.SnakeAndLadder.entities.Dice;
import Practice.SnakeAndLadder.entities.Player;
import Practice.SnakeAndLadder.entities.BoardEntity.BoardEntity;
import Practice.SnakeAndLadder.enums.GameStatus;

public class Game {
    private final Board board;
    private final Queue<Player> players;
    private final Dice dice;
    private GameStatus gameStatus;
    private Player winner;

    public Game(Builder builder){
        this.board = builder.board;
        this.players = new LinkedList<>(builder.players);
        this.dice = builder.dice;
        this.gameStatus = GameStatus.NOT_STARTED;
    }

    public void play(){
        if(players.size() < 2){
            System.out.println("Cannot start game. At least 2 players are required.");
            return;
        }

        this.gameStatus = GameStatus.RUNINNG;
        System.out.println("Game started!");

        while (gameStatus == GameStatus.RUNINNG) {
            Player currentPlayer = players.poll();
            takeTurn(currentPlayer);

            if (gameStatus == GameStatus.RUNINNG) {
                players.add(currentPlayer);
            }
        }
    }


    private void takeTurn(Player player){
        int roll = dice.roll();
        System.out.printf("\n%s's turn. Rolled a %d",player.getName(), roll );

        int currentPosition = player.getPosition();
        int nextPosition = currentPosition+roll;

        if(nextPosition > board.getSize()){
            System.out.printf("Oops, %s needs to land exactly on %d. turn skipped. \n", player.getName(),board.getSize());
            return;
        }

        if(nextPosition == board.getSize()){
            player.setPosition(nextPosition);
            this.winner = player;
            this.gameStatus = GameStatus.FINSHED;
            System.out.printf("Hooray! %s reached the final score %d and won!\n", player.getName(), board.getSize());
            return;
        }

        int finalPosition = board.getFinalPosition(nextPosition);
        
        if (finalPosition > nextPosition) { // Ladder
            System.out.printf("Wow! %s found a ladder 🪜 at %d and climbed to %d.\n", player.getName(), nextPosition, finalPosition);
        } else if (finalPosition < nextPosition) { // Snake
            System.out.printf("Oh no! %s was bitten by a snake 🐍 at %d and slid down to %d.\n", player.getName(), nextPosition, finalPosition);
        } else {
            System.out.printf("%s moved from %d to %d.\n", player.getName(), currentPosition, finalPosition);
        }

        player.setPosition(finalPosition);

        if (roll == 6) {
            System.out.printf("%s rolled a 6 and gets another turn!\n", player.getName());
            takeTurn(player);
        }
    }

     // 🧱 Inner Builder class
    public static class Builder {
        private Board board;
        private Queue<Player> players;
        private Dice dice;

        public Builder setBoard(int boardSize, List<BoardEntity> boardEntities) {
            this.board = new Board(boardSize, boardEntities);
            return this;
        }

        public Builder setPlayers(List<String> playerNames) {
            this.players = new LinkedList<>();
            for (String playerName : playerNames) {
                players.add(new Player(playerName));
                // players.add(new Player(playerName));
            }
            return this;
        }

        public Builder setDice(Dice dice) {
            this.dice = dice;
            return this;
        }

        public Game build() {
            if (board == null || players == null || dice == null) {
                throw new IllegalStateException("Board, Players, and Dice must be set.");
            }
            return new Game(this);
        }
    }
}
