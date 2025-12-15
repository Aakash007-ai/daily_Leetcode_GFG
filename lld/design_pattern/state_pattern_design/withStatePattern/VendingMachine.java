package state_pattern_design.withStatePattern;

public class VendingMachine {
    private VendingMachineState state;

    public VendingMachine(){
        state = new NoCoinState(); // start with initial state
    }

    public void setState(VendingMachineState state){
        this.state = state;
    }

    public void insertCoin(){
        state.insertCoin(this);
    }

    public void pressButton(){
        state.pressButton(this);
    }

    public void refill(){
        state.refill(this);
    }
}
