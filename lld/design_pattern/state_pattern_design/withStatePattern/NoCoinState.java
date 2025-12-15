package state_pattern_design.withStatePattern;

public class NoCoinState implements VendingMachineState {
    public void insertCoin(VendingMachine vendingMachine){
        System.out.println("Coin insert");
        vendingMachine.setState(new HasCoinState());
    }

    public void pressButton(VendingMachine vendingMachine){
        System.out.println("Insert a coin first");
    }

    public void refill(VendingMachine vendingMachine){
        System.out.println("Machine is not empty");
    }
}
