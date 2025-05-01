package javaLang.DesignVendingMachine.impl;

import java.util.List;

import javaLang.DesignVendingMachine.Coin;
import javaLang.DesignVendingMachine.VendingMachine;

public class HasMoneyState implements State {
    //insert coin , select product button or refund

    public HasMoneyState(){
        System.out.println("Currently vending machine is in Has Money State");            
    }

    public void clickOnInsertCoinButton(VendingMachine vendingMachine) throws Exception {
        return ;
    }

    
    public void clickOnStartProductSelectButton(VendingMachine vendingMachine) throws Exception {
        System.out.println("Please select the product to dispense");
        vendingMachine.setVendingMachineState(new ProductSelectState());
    }

    public void insertCoin(VendingMachine vendingMachine,Coin coin) throws Exception {
        System.out.println("Accept the coin");
        vendingMachine.getCoinList().add(coin);
    }

    public List<Coin> refundFullMoney(VendingMachine vendingMachine) throws Exception {
        System.out.println("Refunding the full money");
        vendingMachine.setVendingMachineState(new IdleState(vendingMachine));
        return vendingMachine.getCoinList();
    }

    public void chooseProduct(VendingMachine vendingMachine, int codeNumber) throws Exception {
        throw new Exception("You need to click start product selection button first" null)
    }
    
}
