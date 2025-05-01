package javaLang.DesignVendingMachine.impl;

import java.util.List;

import javaLang.DesignVendingMachine.Coin;
import javaLang.DesignVendingMachine.Item;
import javaLang.DesignVendingMachine.VendingMachine;

public interface State {
    public void clickOnInsertCoinButton(VendingMachine vendingMachine) throws Exception;

    public void clickOnStartProductSelectButton(VendingMachine vendingMachine) throws Exception;

    public void insertCoin(VendingMachine vencdingMachine,Coin coin) throws Exception;

    public void chooseProduct(VendingMachine vendingMachine, int codeNumber) throws Exception;

    public int getChange(int returnChangeMoney) throws Exception;

    public Item dispenseProduct(VendingMachine vendingMachine, int codeNumber) throws Exception;

    public List<Coin> refundFullMoney(VendingMachine vendingMachine) throws Exception;

    public void updateInventory(VendingMachine vendingMachine,Item item,int codeNumber) throws Exception;

}
