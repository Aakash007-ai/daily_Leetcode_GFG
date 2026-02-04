package Practice.FoodDeliverySystem.entities.Order;

import Practice.FoodDeliverySystem.entities.Menu.MenuItem;

public class OrderItem {
    private final MenuItem item;
    private final int quantity;

    public OrderItem(MenuItem item, int quantity){
        this.item = item;
        this.quantity = quantity;
    }
    
    public MenuItem getItem() {
        return item;
    }
    public int getQuantity() {
        return quantity;
    }

}
