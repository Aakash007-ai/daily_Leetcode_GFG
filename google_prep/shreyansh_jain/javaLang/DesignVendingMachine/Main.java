package javaLang.DesignVendingMachine;

import javaLang.DesignVendingMachine.impl.State;

public class Main {
    public static void main(String args[]){
        VendingMachine vendingMachine = new VendingMachine();
        try{
            System.out.println(" | filling up the inventory |");
            fillUpinventory(vendingMachine);
            displayInventory(vendingMachine);

            System.out.println(" | Clicking on insertCoin |");

            State vendingMachineState =vendingMachine.getVendingState();
            vendingMachineState.clickOnInsertCoinButton(vendingMachine);
            vendingMachineState.insertCoin(vendingMachine, Coin.NICKEL);
            vendingMachineState.insertCoin(vendingMachine, Coin.DIME);

          System.out.println(" | Clicking on startProductSelectButton |");
            vendingMachineState.clickOnStartProductSelectButton(vendingMachine);
            vendingMachineState = vendingMachine.getVendingState();
            vendingMachineState.chooseProduct(vendingMachine, 100);

            displayInventory(vendingMachine);
  
        }catch(Exception error){
            System.out.println("Error: " + error.getMessage());
            displayInventory(vendingMachine);
        }
    }

    private static void fillUpinventory(VendingMachine vendingMachine){
        ItemShelf[] itemShelf = vendingMachine.getInventory().getInventory();

        for(int i=0;i< itemShelf.length;i++){
            Item newItem = new Item();
            if(i>=0 && i<3){
                newItem.setType(ItemType.COKE);
                newItem.setPrice(2);
            }else if(i>= 3 && i<5){
                newItem.setType(ItemType.PEPSI);
                newItem.setPrice(9);
            }else if(i>=5 && i<7){
                newItem.setType(ItemType.SODA);
                newItem.setPrice(5);
            }else if(i>=7 && i<10){
                newItem.setType(ItemType.JUICE);
                newItem.setPrice(8);
            }
            itemShelf[i].setItem(newItem);
            itemShelf[i].setSoldOut(false);
        }
    }

    private static void  displayInventory(VendingMachine vendingMachine){
        ItemShelf[] itemShelfs = vendingMachine.getInventory().getInventory();
        for(int i=0;i<itemShelfs.length;i++){
            System.out.println("CodeNumber: " + itemShelfs[i].getCode() + 
            " ItemType: " + itemShelfs[i].getItem().getType() + 
            " Price: " + itemShelfs[i].getItem().getPrice() + 
            " SoldOut: " + itemShelfs[i].isSoldOut()); 
        }
    }
}
