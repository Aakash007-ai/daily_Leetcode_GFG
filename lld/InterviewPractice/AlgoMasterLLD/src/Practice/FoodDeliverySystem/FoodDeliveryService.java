package Practice.FoodDeliverySystem;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.concurrent.ConcurrentHashMap;

import Practice.FoodDeliverySystem.entities.Address;
import Practice.FoodDeliverySystem.entities.Restaurant;
import Practice.FoodDeliverySystem.entities.Menu.Menu;
import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.entities.Order.OrderItem;
import Practice.FoodDeliverySystem.entities.user.Customer;
import Practice.FoodDeliverySystem.entities.user.DeliveryAgent;
import Practice.FoodDeliverySystem.enums.OrderStatus;
import Practice.FoodDeliverySystem.strategy.deliveryAssignmentStrategy.DeliveryAssignmentStrategy;
import Practice.FoodDeliverySystem.strategy.searchStrategy.RestaurantSearchStrategy;

public class FoodDeliveryService {
    private static volatile FoodDeliveryService instance;

    private final Map<String, Customer> customers = new ConcurrentHashMap<>();
    private final Map<String,Restaurant> restaurants = new ConcurrentHashMap<>();
    private final Map<String,DeliveryAgent> deliveryAgents = new ConcurrentHashMap<>();
    private final Map<String,Order> orders = new ConcurrentHashMap<>();
    private DeliveryAssignmentStrategy assignmentStrategy;

    public DeliveryAssignmentStrategy getAssignmentStrategy() {
        return assignmentStrategy;
    }

    public void setAssignmentStrategy(DeliveryAssignmentStrategy assignmentStrategy) {
        this.assignmentStrategy = assignmentStrategy;
    }


    public static FoodDeliveryService getInstance(){
        if(instance == null){
            synchronized(FoodDeliveryService.class){
                if(instance == null) instance = new FoodDeliveryService();
            }
        }
        return instance;
    }

    // --- Registration ---
    public Customer registerCustomer(String name, String phone, Address address) {
        Customer customer = new Customer(name, phone, address);
        customers.put(customer.getId(), customer);
        return customer;
    }

    public Restaurant registerRestaurant(String name, Address address) {
        Restaurant restaurant = new Restaurant(name, address);
        restaurants.put(restaurant.getId(), restaurant);
        return restaurant;
    }

    public DeliveryAgent registerDeliveryAgent(String name, String phone, Address initialLocation) {
        DeliveryAgent deliveryAgent = new DeliveryAgent(name, phone, initialLocation);
        deliveryAgents.put(deliveryAgent.getId(), deliveryAgent);
        return deliveryAgent;
    }

    public Order placeOrder(String customerId, String restaurantId, List<OrderItem> items){
        Customer customer = customers.get(customerId);
        Restaurant restaurant = restaurants.get(restaurantId);

        if(customer == null || restaurant == null) throw new NoSuchElementException("Customer or restaurant not found");

        Order order = new Order(customer, restaurant, items);
        orders.put(restaurantId, order);
        customer.addToOrderHistory(order);
        System.out.printf("Order %s is placed by %s at %s",order.getId(), customer.getName(), restaurant.getName());
        order.setStatus(OrderStatus.PENDING);
        return order;
    }

    public void updateOrderStatus(String orderId, OrderStatus newStatus){
        Order order = orders.get(orderId);
        if(order == null){
            System.out.println("ERROR : Order with ID "+ order.getId() + " not found.");
            return;
        }

        // Delegate the cancellation logic to the Order object itself.
        if (order.cancel()) {
            System.out.println("SUCCESS: Order " + orderId + " has been successfully canceled.");
        } else {
            System.out.println("FAILED: Order " + orderId + " could not be canceled. Its status is: " + order.getStatus());
        }
    }

    public void assignDelivery(Order order){
        List<DeliveryAgent> avaialableAgents = new ArrayList<>(deliveryAgents.values()); // new
        // NEW -> check this ifPresentOrElse it takes a fucntion as parameter
        this.assignmentStrategy.findAgent(order, avaialableAgents).ifPresentOrElse(
            agent -> {
                order.assignDeliveryAgent(agent);
                System.out.printf("Agent %s (dist : %.2f) assigned to order %s.\n",
                    agent.getName(),
                    agent.getCurrentLocation().distanceTo(order.getRestaurant().getAddress()),
                    order.getId());
            },
            () -> System.out.println("No available delivery agents found for order "+ order.getId())
        );
    }

    public List<Restaurant> searchRestaurants(List<RestaurantSearchStrategy> searchStrategies){
        List<Restaurant> results = new ArrayList<>(restaurants.values());
        // TODO :- use chain of responsibility design pattern
        for(RestaurantSearchStrategy strategy : searchStrategies){
            results = strategy.filter(results);
        }

        return results;
    }

    public Menu getRestaurant(String restaurantId){
        Restaurant restaurant = restaurants.get(restaurantId);
        if(restaurant == null){
            throw new NoSuchElementException("\"Restaurant with ID \" + restaurantId + \" not found.\"");
        }
        // restaurants.getOrDefault(restaurantId,null)
        return restaurant.getMenu();
    }

     

}
