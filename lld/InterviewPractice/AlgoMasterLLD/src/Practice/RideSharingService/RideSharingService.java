package Practice.RideSharingService;

import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.concurrent.ConcurrentHashMap;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.entities.Trip;
import Practice.RideSharingService.entities.user.Driver;
import Practice.RideSharingService.entities.user.Rider;
import Practice.RideSharingService.enums.DriverStatus;
import Practice.RideSharingService.enums.RideType;
import Practice.RideSharingService.strategy.matching.DriverMatchingStrategy;
import Practice.RideSharingService.strategy.matching.NearestDriverMatchingStrategy;
import Practice.RideSharingService.strategy.pricing.PricingStrategy;
import Practice.RideSharingService.strategy.pricing.VehicleBasedPriceStrategy;

public class RideSharingService {
    private static volatile RideSharingService instance;
    private final Map<String, Driver> drivers = new ConcurrentHashMap<>();
    private final Map<String, Rider> riders = new ConcurrentHashMap<>();
    private final Map<String, Trip> trips = new ConcurrentHashMap<>();
    private DriverMatchingStrategy driverMatchingStrategy = new NearestDriverMatchingStrategy();
    private PricingStrategy pricingStrategy = new VehicleBasedPriceStrategy();
    private RideSharingService(){}

    public static synchronized RideSharingService getInstance(){
        if(instance == null){
            instance = new RideSharingService();
        }
        return instance;
    }

    public Trip requestTrip(String id, Location pickupLocation, Location dropLocation, RideType rideType){
        Rider rider = getRiders(id);
        if(rider == null){
            throw new NoSuchElementException("Rider not found");
        }
        System.out.println("\n-----------New Ride Request from "+ id + " to this Location( " + dropLocation.toString()+" )");

        List<Driver> availabelDrivers = this.driverMatchingStrategy.findDriver(List.copyOf(drivers.values()), pickupLocation, rideType);

        if(availabelDrivers.size() == 0){
            throw new NoSuchElementException("No Driver is free at this time");
        }

        double fare = pricingStrategy.calculateFare(pickupLocation, dropLocation, rideType);

        Trip trip = new Trip.TripBuilder()
                                .setFare(fare)
                                .setDropOffLocation(dropLocation)
                                .setPickupLocation(pickupLocation)
                                .setRider(rider)
                                .build();

        // trip.getTripState().request(trip);
        trips.put(trip.getId(), trip);

        trip.getTripState().request(trip);

        List<Driver> availableDrivers = driverMatchingStrategy.findDriver(availabelDrivers, pickupLocation, rideType);
        for(Driver driver : availableDrivers){
            System.out.println(" > Notifying " + driver.getName() + " at " + driver.getCurrLocation());
            driver.onUpdate(trip);
        }
        return trip;
    }

    public void acceptRide(String driverId, String tripId) {
        Driver driver = drivers.get(driverId);
        Trip trip = trips.get(tripId);
        if (driver == null || trip == null)
            throw new NoSuchElementException("Driver or Trip not found");

        System.out.println("\n--- Driver " + driver.getName() + " accepted the ride ---");

        driver.setDriverStatus(DriverStatus.IN_TRIP);
        trip.assignDriver(driver);
    }

    public void startTrip(String tripId) {
        Trip trip = trips.get(tripId);
        if (trip == null)
            throw new NoSuchElementException("Trip not found");
        System.out.println("\n--- Trip " + trip.getId() + " is starting ---");
        trip.startTrip();
    }


    public void addDriver(Driver driver){
        drivers.put(driver.getId(), driver);
    }

    public void addRider(Rider rider){
        riders.put(rider.getId(), rider);
    }
    
    public Rider getRiders(String id) {
        return riders.getOrDefault(id, null);
    }

    public Driver getDrivers(String id) {
        return drivers.getOrDefault(id, null);
    }


}
