package TicTacToe.enums;

public enum Symbol {
    X('X'),
    O('O'),
    EMPTY('_');

    private final char symbol;

    public char getSymbol() {
        return symbol;
    }
    
    Symbol(char c) {
        this.symbol = c;
    }
}
