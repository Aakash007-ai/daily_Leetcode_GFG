package Practice.FoodDeliverySystem.strategy.searchStrategy;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import Practice.FoodDeliverySystem.entities.Address;
import Practice.FoodDeliverySystem.entities.Restaurant;

public class SearchByProximityStrategy implements RestaurantSearchStrategy {
    private final Address userLocation;
    private final double maxDistance;
    
    public SearchByProximityStrategy(Address userLocation, double maxDistance) {
        this.userLocation = userLocation;
        this.maxDistance = maxDistance;
    }

    @Override
    public List<Restaurant> filter(List<Restaurant> allRestaurants) {
        return allRestaurants.stream()
                // filter all locations within maxDistance
                .filter(r -> userLocation.distanceTo(r.getAddress()) <= maxDistance)
                // now sort them by distance
                .sorted(Comparator.comparingDouble(r-> userLocation.distanceTo(r.getAddress())))
                .collect(Collectors.toList());
    }
    
}
