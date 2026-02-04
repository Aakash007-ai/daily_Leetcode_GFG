package Practice.FoodDeliverySystem.strategy.deliveryAssignmentStrategy;

import java.util.List;
import java.util.Optional;

import Practice.FoodDeliverySystem.entities.Order.Order;
import Practice.FoodDeliverySystem.entities.user.DeliveryAgent;

public interface DeliveryAssignmentStrategy {
    Optional<DeliveryAgent> findAgent(Order order,List<DeliveryAgent> deliveryAgent);
}
