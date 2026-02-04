package Practice.FoodDeliverySystem.strategy.searchStrategy;

import java.util.List;
import java.util.stream.Collectors;

import Practice.FoodDeliverySystem.entities.Restaurant;

public class SearchByCityStrategy implements RestaurantSearchStrategy {
    private final String city;

    public SearchByCityStrategy(String city){
        this.city = city;
    }

    @Override
    public List<Restaurant> filter(List<Restaurant> allRestaurants) {
        return allRestaurants.stream()
                .filter(r -> r.getAddress().getCity().equalsIgnoreCase(city))
                .collect(Collectors.toList());
    }
    
}
