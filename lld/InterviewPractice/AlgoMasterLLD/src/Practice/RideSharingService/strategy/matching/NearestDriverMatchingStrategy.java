package Practice.RideSharingService.strategy.matching;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.entities.user.Driver;
import Practice.RideSharingService.enums.DriverStatus;
import Practice.RideSharingService.enums.RideType;


public class NearestDriverMatchingStrategy implements DriverMatchingStrategy{
    private static final double MAX_DISTANCE_KM = 5.0;
    @Override
    public List<Driver> findDriver(List<Driver> allDrivers, Location pickupLocation, RideType rideType) {
        return allDrivers.stream()
                .filter(driver -> driver.getDriverStatus() == DriverStatus.ONLINE)
                .filter(driver -> driver.getVehicle().getRideType() == rideType )
                .filter(driver -> pickupLocation.distanceTo(driver.getCurrLocation()) <= MAX_DISTANCE_KM )
                .sorted(Comparator.comparingDouble(driver -> pickupLocation.distanceTo(driver.getCurrLocation())))
                .collect(Collectors.toList());
    }
}
