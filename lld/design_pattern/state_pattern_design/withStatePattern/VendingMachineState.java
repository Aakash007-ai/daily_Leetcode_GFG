package state_pattern_design.withStatePattern;

public interface VendingMachineState {
    void insertCoin(VendingMachine vendingMachine);
    void pressButton(VendingMachine vendingMachine);
    void refill(VendingMachine vendingMachine);
}
