package Practice.FoodDeliverySystem.entities.Order;

import java.util.List;
import java.util.UUID;

import Practice.FoodDeliverySystem.entities.Restaurant;
import Practice.FoodDeliverySystem.entities.user.Customer;
import Practice.FoodDeliverySystem.entities.user.DeliveryAgent;
import Practice.FoodDeliverySystem.enums.OrderStatus;
import Practice.FoodDeliverySystem.observer.OrderObservable;

public class Order extends OrderObservable {
    private final String id;
    private final Customer customer;
    private final Restaurant restaurant;
    private final List<OrderItem> items;
    private OrderStatus status;


    private DeliveryAgent deliveryAgent;
    
    public DeliveryAgent getDeliveryAgent() {
        return deliveryAgent;
    }

    public Order(Customer customer, Restaurant restaurant, List<OrderItem> items) {
        this.id = UUID.randomUUID().toString();
        this.customer = customer;
        this.restaurant = restaurant;
        this.items = items;
        this.status = OrderStatus.PENDING;
        this.adddObserver(restaurant);
        this.adddObserver(customer);
    }

    public void setStatus(OrderStatus newStatus){
        if(this.status != newStatus){
            this.status= newStatus;
            this.notifyObservers();
        }
    }

    public boolean cancel(){
        if(this.status == OrderStatus.PENDING){
            setStatus(OrderStatus.CANCELLED);
            return true;
        }
        return false;
    }

    // public boolean cancel(){
    //     if(status == OrderStatus.CANCELLED){

    //     }
    // }

    public void assignDeliveryAgent(DeliveryAgent agent){
        this.deliveryAgent = agent;
        adddObserver(agent);
        agent.setAvailable(false);
    }

    public String getId() {
        return id;
    }

    public Customer getCustomer() {
        return customer;
    }
    public Restaurant getRestaurant() {
        return restaurant;
    }
    public OrderStatus getStatus() {
        return status;
    }

}
