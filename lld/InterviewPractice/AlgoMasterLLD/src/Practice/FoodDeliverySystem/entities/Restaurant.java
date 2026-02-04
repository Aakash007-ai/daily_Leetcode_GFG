package Practice.FoodDeliverySystem.entities;

import java.util.UUID;

import Practice.FoodDeliverySystem.entities.Menu.Menu;
import Practice.FoodDeliverySystem.entities.Menu.MenuItem;
import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.observer.OderObserver;
import Practice.FoodDeliverySystem.observer.OrderObservable;


public class Restaurant implements OderObserver {
    private final String id;
    private final String name;
    private final Address address;
    private final Menu menu;
    
    public Menu getMenu() {
        return menu;
    }

    public Restaurant(String name, Address address) {
        this.id = UUID.randomUUID().toString();
        this.name = name;
        this.address = address;
        this.menu = new Menu();
    }

    public void addToMenu(MenuItem item){
        this.menu.addItem(item);
    }

    public String getId(){
        return this.id;
    }

    public String getName(){
        return this.name;
    }
    
    public Address getAddress() {
        return address;
    }

    @Override
    public void onUpdate(Order order) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'onUpdate'");
    }

}
