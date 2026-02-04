package Practice.RideSharingService.strategy.pricing;

import java.util.Map;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.enums.RideType;

public class VehicleBasedPriceStrategy implements PricingStrategy{
    private static final double BASE_PRICE = 5;
    private static final Map<RideType,Double> RATE_PER_KM = Map.of(
        RideType.SEDAN, 1.50,
        RideType.SUV, 2.00,
        RideType.AUTO, 1.00
    );

    @Override
    public double calculateFare(Location pickupLocation, Location dropLocation, RideType rideType) {
        return BASE_PRICE*RATE_PER_KM.get(rideType)*pickupLocation.distanceTo(dropLocation);
    }
    
}
