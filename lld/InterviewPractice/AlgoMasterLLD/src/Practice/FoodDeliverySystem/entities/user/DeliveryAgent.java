package Practice.FoodDeliverySystem.entities.user;

import java.util.concurrent.atomic.AtomicBoolean;

import Practice.FoodDeliverySystem.entities.Address;
import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.observer.OderObserver;

public class DeliveryAgent extends User implements OderObserver {
    private final AtomicBoolean isAvailable = new AtomicBoolean(true);
    private Address currentLocation;

    public DeliveryAgent(String name, String phone, Address currAddress) {
        super(name, phone);
        this.currentLocation = currAddress;
    }

    @Override
    public void onUpdate(Order order) {
        System.out.printf("--- Notification for Delivery Agent %s ---\n", getName());
        System.out.printf("  Order %s update: Status is %s.\n", order.getId(), order.getStatus());
        System.out.println("-------------------------------------------\n");
    }

    public synchronized boolean isAvailable(){
        return this.isAvailable.get();
    }
    public void setAvailable(boolean available) { this.isAvailable.set(available); }
    public void setCurrentLocation(Address currentLocation) { this.currentLocation = currentLocation; }
    public Address getCurrentLocation() { return currentLocation; }
    
}
