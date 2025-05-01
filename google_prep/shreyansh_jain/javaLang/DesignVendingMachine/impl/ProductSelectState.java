package javaLang.DesignVendingMachine.impl;

import java.util.List;

import javaLang.DesignVendingMachine.Coin;
import javaLang.DesignVendingMachine.Item;
import javaLang.DesignVendingMachine.VendingMachine;

public class ProductSelectState implements State {
    public ProductSelectState() {
        System.out.println("Currently vending machine is in Product Selection State");
    }

    @Override
    public void clickOnInsertCoinButton(VendingMachine vendingMachine) throws Exception {
        throw new Exception("You cannot click on insert coin button in product selection state");
    }

    @Override
    public void chooseProduct(VendingMachine vendingMachine,int codeNumber) throws Exception {

        // 1. get item of this code number from inventory
        Item item = vendingMachine.getInventory().getId(codeNumber);// .get(codeNumber);

        //2. check if total amount paid by user
        int paidByUser = 0;
        for(Coin coin : vendingMachine.getCoinsList()){
            paidByUser += coin.value;
        }

        //3. comapare product price and amount paid by user
        if(paidByUser < item.getPrice()){
            System.out.println("Insufficient amount, Product you have selected is for " + item.getPrice() + " and you have paid " + paidByUser);
            refundFullMoney(vendingMachine);
            throw new Exception("Insufficient amount, Product you have selected is of higher price");
        }else if(paidByUser >= item.getPrice()){

            if(paidByUser > item.getPrice()){
                getChange(paidByUser - item.getPrice()); //refund extra money
            }
            vendingMachine.setVendingMachineState(new DispenseState(vendingMachine,codeNumber));
        }
    }

    @Override
    public int getChange(int returnExtraMoney) throws Exception {
        System.out.println("Return the change in the coined dispense tray");
        return returnExtraMoney;
    }

    @Override
    public List<C.oin> refundFullMoney(VendingMachine vendingMachine) throws Exception {
        System.out.println("Refund the full amount back in the Coin dispense tray");
        vendingMachine.setVendingMachineState(new IdleState(vendingMachine));
        return vendingMachine.getCoinList();
    }

    //throw exception for rest of the methods
    @Override
    public Item dispenseProduct(VendingMachine vendingMachine,int codeNumber) throws Exception {
        throw new Exception("Product cannot be dispensed in product selection state");
    }

    
}
