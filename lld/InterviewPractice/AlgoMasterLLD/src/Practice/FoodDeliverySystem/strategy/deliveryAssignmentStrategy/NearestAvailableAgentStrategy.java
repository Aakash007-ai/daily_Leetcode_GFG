package Practice.FoodDeliverySystem.strategy.deliveryAssignmentStrategy;

import java.util.Comparator;
import java.util.List;
import java.util.Optional;

import Practice.FoodDeliverySystem.entities.Address;
import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.entities.user.DeliveryAgent;

public class NearestAvailableAgentStrategy implements DeliveryAssignmentStrategy{

    @Override
    public Optional<DeliveryAgent> findAgent(Order order, List<DeliveryAgent> deliveryAgent) {
        Address restaurantAddress = order.getRestaurant().getAddress();
        Address customerAddress = order.getCustomer().getAddress();

        return deliveryAgent.stream()
                .filter(DeliveryAgent:: isAvailable)
                .min(Comparator.comparingDouble(agent -> calculateTotalDistance(agent, restaurantAddress, customerAddress)));
    }

    private double calculateTotalDistance(DeliveryAgent agent, Address restauAddress, Address customAddress){
        double agentToRestaurantDist = agent.getCurrentLocation().distanceTo(restauAddress);
        double restaurantToCustmerDist = restauAddress.distanceTo(customAddress);
        return agentToRestaurantDist+restaurantToCustmerDist;
    }
    
}
