package javaLang.DesignVendingMachine;

import java.util.ArrayList;
import java.util.List;

import javaLang.DesignVendingMachine.impl.IdleState;
import javaLang.DesignVendingMachine.impl.State;

public class VendingMachine {
    private State vendingMachineState;
    private Inventory inventory;
    private List<Coin> coinList; //list of coin user has put

    public VendingMachine(){
        this.vendingMachineState = new IdleState();
        this.inventory= new Inventory(10);
        this.coinList = new ArrayList<>();
    }

    public State getVendingState(){
        return this.vendingMachineState;
    }

    public void setVendingMachineState(State vendingMachineState){
        this.vendingMachineState = vendingMachineState;
    }
    
    public Inventory getInventory(){
        return this.inventory;
    }

    public void setInventory(Inventory inventory){
        this.inventory = inventory;
    }

    public List<Coin> getCoinsList(){
        return this.coinList;
    }
    public void setCoinList(List<Coin> coinList){
        this.coinList = coinList;
    }
}
