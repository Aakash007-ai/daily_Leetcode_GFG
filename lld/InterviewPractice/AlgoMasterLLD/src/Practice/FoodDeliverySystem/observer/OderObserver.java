package Practice.FoodDeliverySystem.observer;

import Practice.FoodDeliverySystem.entities.Order.Order;

public interface OderObserver {
    public void onUpdate(Order order);
}
