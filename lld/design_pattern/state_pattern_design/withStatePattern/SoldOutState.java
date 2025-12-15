package state_pattern_design.withStatePattern;

public class SoldOutState implements VendingMachineState {
    public void insertCoin(VendingMachine vendingMachine){
        System.out.println("Machine is sold out");
    }

    public void pressButton(VendingMachine vendingMachine){
        System.out.println("Machine is sold out");
    }

    public void refill(VendingMachine vendingMachine){
        System.out.println("Machine refilled");
        vendingMachine.setState(new NoCoinState());
    }
    
}
