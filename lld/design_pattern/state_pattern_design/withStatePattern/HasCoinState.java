package state_pattern_design.withStatePattern;

public class HasCoinState implements VendingMachineState {
    public void insertCoin(VendingMachine vendingMachine){
        System.out.println("Coin already inserted");
    }

    public void pressButton(VendingMachine vendingMachine){
        System.out.println("Product Added");
        vendingMachine.setState(new NoCoinState()); // go back to original state
    }

    public void refill(VendingMachine vendingMachine){
        System.out.println("Machine is not empty");
    }
}
