package Practice.FoodDeliverySystem.strategy.searchStrategy;

import java.util.List;
import java.util.stream.Collectors;

import Practice.FoodDeliverySystem.entities.Restaurant;



public class SearchByMenuKeyword implements RestaurantSearchStrategy {
    private final String keyword;

    public SearchByMenuKeyword(String keyword) {
        this.keyword = keyword;
    }

    @Override
    public List<Restaurant> filter(List<Restaurant> allRestaurants) {
        return allRestaurants.stream()
        .filter(r -> r.getMenu().getItems().values().stream()
                        .anyMatch(item -> item.getName().toLowerCase().contains(keyword)))
                    .collect(Collectors.toList());
    }


}
