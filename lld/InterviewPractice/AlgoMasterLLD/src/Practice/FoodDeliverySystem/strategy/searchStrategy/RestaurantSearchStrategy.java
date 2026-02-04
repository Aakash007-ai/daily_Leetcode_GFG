package Practice.FoodDeliverySystem.strategy.searchStrategy;

import java.util.List;

import Practice.FoodDeliverySystem.entities.Restaurant;

public interface RestaurantSearchStrategy {
    List<Restaurant> filter(List<Restaurant> allRestaurants);
}
