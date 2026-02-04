package Practice.RideSharingService.strategy.matching;

import java.util.List;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.entities.user.Driver;
import Practice.RideSharingService.enums.RideType;

public interface DriverMatchingStrategy {
    public List<Driver> findDriver(List<Driver> drivers,Location pickupLocation, RideType rideType);
}




















