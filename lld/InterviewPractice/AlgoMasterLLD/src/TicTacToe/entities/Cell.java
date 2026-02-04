package TicTacToe.entities;

import TicTacToe.enums.Symbol;

public class Cell {
    private Symbol symbol;

    public Symbol getSymbol() {
        return symbol;
    }

    public void setSymbol(Symbol symbol) {
        this.symbol = symbol;
    }

    public Cell(){
        this.symbol = Symbol.EMPTY; 
    }

    

}
