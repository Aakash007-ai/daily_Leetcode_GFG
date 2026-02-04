package Practice.RideSharingService.strategy.pricing;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.enums.RideType;

public interface PricingStrategy {
    public double calculateFare(Location pickupLocation, Location dropLocation, RideType rideType);
}
