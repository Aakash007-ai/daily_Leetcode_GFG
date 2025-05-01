package javaLang.DesignVendingMachine.impl;

import java.util.ArrayList;

import javaLang.DesignVendingMachine.Coin;
import javaLang.DesignVendingMachine.VendingMachine;

public class IdleState implements State{
    public IdleState() {
        System.out.println("Vending Machine is in Idle State");
    }

    public IdleState(VendingMachine vendingMachine){
        System.out.println("Vending Machine is in Idle State");
        vendingMachine.setCoinList(new ArrayList<>());
    }

    // we can only click on insert coin button in idle state , rest of button we throw Exception
    public void clickOnInsertCoinButton(VendingMachine vendingMachine) throws Exception {
        System.out.println("Please insert coin to start the vending machine");
        vendingMachine.setVendingMachineState(new HasMoneyState());
    }

    
    public void clickOnStartProductSelectButton(VendingMachine vendingMachine) throws Exception {
        throw new Exception("First you need to insert coin to start the vending machine");
    }

    public void insertCoin(VendingMachine vendingMachine,Coin coin) throws Exception {
        throw new Exception("you cannot insert coin in idle state");
    }
    
    public void chooseProduct(VendingMachine vendingMachine, int codeNumber) throws Exception {
        throw new Exception("You cannot choose product in idle state");
    }

}
