package state_pattern_design.without_state_pattern;

public class VendingMachine {
    private String state = "NoCoin"; //possible state NoCoin , HasCoin, SoldOut

    public void insertCoin(){
        if(state.equals("NoCoin")){
            System.out.println("Coin inserted");
            state = "HasCoin";
        }else if(state.equals("HasCoin")){
            System.out.println("Coin already inserted");
        }else if(state.equals("SoldOut")){
            System.out.println("Machine is sold out");
        }
    }

    public void pressButton(){
        if(state.equals("NoCoin")){
            System.out.println("Insert a coin first");
        }else if(state.equals("HasCoin")){
            System.out.println("Product dispatched");
            state = "NoCoin";
        }else if(state.equals("SoldOut")){
            System.out.println("Machine is sold out");
        }
    }

    public void refill(){
        if(state.equals("SoldOut")){
            System.out.println("Machine refilled");
            state = "NoCoin";
        }else {
            System.out.println("Machine is empty");
        }
    }

    public String getState(){
        return this.state;
    }
}
