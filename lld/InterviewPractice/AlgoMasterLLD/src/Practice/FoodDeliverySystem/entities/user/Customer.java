package Practice.FoodDeliverySystem.entities.user;

import java.util.ArrayList;
import java.util.List;

import Practice.FoodDeliverySystem.entities.Address;
import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.observer.OderObserver;

public class Customer extends User implements OderObserver{
    private Address address;
    private final List<Order> orderHistory = new ArrayList<>();

    public Customer(String name, String phone, Address address) {
        super(name, phone);
        this.address = address;
    }

    @Override
    public void onUpdate(Order order) {
        System.out.printf("---Notification for Customer %s ---\n",getName());
        System.out.printf("Order %s is now %s.\n",order.getId(), order.getStatus());
        System.out.println("------------------------------\n");
       }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public List<Order> getOrderHistory() {
        return orderHistory;
    }

    public void addToOrderHistory(Order order){
        this.orderHistory.add(order);
    }
    
}
