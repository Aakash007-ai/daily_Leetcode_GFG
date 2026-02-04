package Practice.FoodDeliverySystem.entities.Menu;

import java.util.HashMap;
import java.util.Map;


public class Menu {
    private final Map<String, MenuItem> items = new HashMap<>();

    public Map<String, MenuItem> getItems() {
        return items;
    }

    public void addItem(MenuItem item){
        this.items.put(item.getId(), item);
    }

    public MenuItem getItem(String id){ 
        return items.get(id);
    }
    
}
