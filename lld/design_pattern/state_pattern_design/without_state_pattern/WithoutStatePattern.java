package state_pattern_design.without_state_pattern;

public class WithoutStatePattern {
    public static void main(String[] args){
        VendingMachine vendingMachine = new VendingMachine();

        vendingMachine.insertCoin();
        vendingMachine.pressButton();
        vendingMachine.insertCoin();
        vendingMachine.pressButton();

        vendingMachine.refill();
    }
}
