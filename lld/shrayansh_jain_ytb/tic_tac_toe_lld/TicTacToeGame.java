package lld.shrayansh_jain_ytb.tic_tac_toe_lld;
//Dequeu and LinkedList
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.*;

import lld.shrayansh_jain_ytb.tic_tac_toe_lld.Model.Board;
import lld.shrayansh_jain_ytb.tic_tac_toe_lld.Model.Player;
import lld.shrayansh_jain_ytb.tic_tac_toe_lld.Model.PlayingPieceO;
import lld.shrayansh_jain_ytb.tic_tac_toe_lld.Model.PlayingPieceX;

public class TicTacToeGame {
    Deque<Player> players;
    Board gameBoard;

    public void initializeGame(){
        //creating 2 Players
        players = LinkedList<>();
        PlayingPieceX crossPiece = new PlayingPieceX();
        Player player1 = new Player("Player 1", crossPiece);
        
        PlayingPieceO noughtsPiece = new PlayingPieceO();
        Player player2 = new Player("Player 2",noughtsPiece);

        players.add(player1);
        players.add(player2);

        //initialize board
        gameBoard = new Board(3);
    }

    public String startGame(){
        boolean noWinner =true;

        while(noWinner){
            Player playerTurn = players.removeFirst();
            gameBoard.printBoard();

            List<Pair<Integer,Integer>> freeSpaces = gameBoard.getFreeCells();

            if(freeSpaces.isEmpty()){
                noWinner= false;
                continue;
            }

            System.out.print("Player: " + playerTurn.name + "Enter row,column: ");
            Scanner inputScanner = new Scanner(System.in);
            String s = inputScanner.nextLine();
            String[] values = s.split(",");
            int inputRow = Integer.valueOf(values[0]);
            int inputColumn = Integer.valueOf(values[1]);

            //place piece
            boolean pieceAddedSuccessfully = gameBoard.addPiece(inputRow,inputColumn);

            if(!pieceAddedSuccessfully){
                System.out.println("Incorrect position chosen , try again"
                player.addFirst(playerTurn));
                continue;
            }

            players.addLast(playerTurn);//now his turn came when all will stop playing 

            boolean  winner=isThereWinner(inputRow,inputColumn,playerTurn);//whether after putting in that place he become winner or not
            if(winner){
                return playerTurn.name;
            }
        }
        return "tie";
    }
    public boolean isThereWinner(int row,int column,PieceType pieceType){
        boolean rowMatch=true;
        boolean columnMatch=true;
        boolean diagonalMatch=true;
        boolean antiDiagonalMatch=true;

        //check that column of row
        for(int i=0;i<gameBoard.size;i++){//complex d.s
            if(gameBoard.board[row][i]==null || gameBoard.board[row][i].pieceType != pieceType){
                columnMatch =false;
            }
        }

        for(int i=0,i<gameBoard.size;i++){
            if(gameBoard.board[i][column]==null || gameBoard.board[i][column].pieceType != pieceType){
                columnMatch= false;
            }
        }

        for(int i=0,j=0;i<gameBoard.size();i++;j++){
            if(gameBoard.board[i][j]==null || gameBoard[i][j].pieceType != pieceType){
                diagonalMatch=false;
            }
        }

        for(int i=0,j=gameBoard.size-1;i<gameBoard.size;i++;j--){
            if(gameBoard.board[i][j]==null || gameBoard[i][j].pieceType != pieceType){
                antiDiagonalMatch=false;
            }
        }

        //if any of them is true player win
        return rowMatch || columnMatch || diagonalMatch || antiDiagonalMatch;


    }
}
