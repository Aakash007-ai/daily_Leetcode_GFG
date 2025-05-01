package javaLang.DesignVendingMachine;

public class Item {
    ItemType itemType;
    int price;

    public ItemType getType(){
        return itemType;
    }

    public void setType(ItemType itemType){
        this.itemType = itemType;
    }

    public int getPrice(){
        return price;
    }

    public void setPrice(int price){
        this.price = price;
    }
}
