package lld.shrayansh_jain_ytb.tic_tac_toe_lld;

public class Main {
    public static void main(String args[]){
        TicTacToeGame game = new TicTacToeGame();
        game.initializeGame();
        System.out.println("Game winner is : " + game.startGame());
    }   
}
