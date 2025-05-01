package javaLang.DesignVendingMachine.impl;

import java.util.List;

import javaLang.DesignVendingMachine.Coin;
import javaLang.DesignVendingMachine.Item;
import javaLang.DesignVendingMachine.VendingMachine;

public class DispenseState implements State {
    DispenseState(VendingMachine vendingMachine, int codeNumber) throws Exception{
        System.out.println("Currently vending machine is in Dispense State");
        dispenseProduct(vendingMachine, codeNumber);
    }

    @Overrride
    public void clickOnInsertCoinButton(VendingMachine vendingMachine) throws Exception {
        throw new Exception("You cannot click on insert coin button in dispense state");
    }

    @Override
    public void clickOnStartProductSelectButton(VendingMachine vendingMachine) throws Exception {
        throw new Exception("You cannot click on start product select button in dispense state");
    }
    
    @Override
    public void insertCoin(VendingMachine vendingMachine,Coin coin) throws Exception {
        throw new Exception("You cannot insert coin in dispense state");
    }

    @Override
    public void chooseProduct(VendingMachine vendingMachine, int codeNumber) throws Exception {
        throw new Exception("You cannot choose product in dispense state");
    }

    @Override
    public int getChange(int returnChangeMoney) throws Exception {
        System.out.println("You cannot cancel the product in dispense state, please take the product first");
        throw new Exception("product cannot returned in disposed state");
    }

    @Override
    public List<Coin> refundFullMoney(VendingMachine vendingMachine) throws Exception {
        System.out.println("Refund cannot happen in dispense state");
        throw new Exception("refund cannot happen in dispense state");
    }

    @Override
    public Item dispenseProduct(VendingMachine vendingMachine,int codeNumber) throws Exception {
        System.out.println("Product has bee dispensed, please take the product from the tray");
        Item item = vendingMachine.getInventory().getCodeNumber();
        vendingMachine.setVendingMachineState(new IdleState(vendingMachine));
        return item;
    }

    @Override
    public void updateInventory(VendingMachine vendingMachine,Item item,int codeNumber) throws Exception {
        System.out.println("Product has been dispensed, please take the product from the tray");
        throw new Exception("inventory cannot be updated in Dispense State" null)
    }


}
