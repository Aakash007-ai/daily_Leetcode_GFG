package Practice.RideSharingService.entities;
import java.util.UUID;

import Practice.RideSharingService.entities.user.Driver;
import Practice.RideSharingService.entities.user.Rider;
import Practice.RideSharingService.enums.TripStatus;
import Practice.RideSharingService.observer.TripObservable;
import Practice.RideSharingService.state.RequestedState;
import Practice.RideSharingService.state.TripState;

// LEARN :- first work upon requirements then later on bonus
// since trip has mulitple state with having mulitple fucntion user can perform common in state or differnt
// so we use Builder pattern
public class Trip extends TripObservable {
    private final String id;
    private final Rider rider;
    private Driver driver;
    private Location pickUpLocation;
    private Location dropOffLocation;
    private final double fare;
    private TripStatus tripStatus;
    private TripState tripState;

    public Trip(TripBuilder tripBuilder){
        this.id = tripBuilder.id;
        this.rider = tripBuilder.rider;
        this.pickUpLocation = tripBuilder.pickupLocation;
        this.dropOffLocation = tripBuilder.dropOffLocation;
        this.fare = tripBuilder.fare;

        tripStatus = TripStatus.REQUESTED;
        this.tripState = new RequestedState();
    }

    public void startTrip() {
        tripState.start(this);
        notifyObserver();
    }
    
    public void endTrip() {
        tripState.end(this);
        notifyObserver();
    }

    public void assignDriver(Driver driver) {
        this.driver = driver;
    }

    // getters
    public Rider getRider() {
        return rider;
    }

    public String getId() {
        return id;
    }

    public Driver getDriver() {
        return driver;
    }

    public Location getPickUpLocation() {
        return pickUpLocation;
    }

    public Location getDropOffLocation() {
        return dropOffLocation;
    }

    public double getFare() {
        return fare;
    }

    public TripStatus getTripStatus() {
        return tripStatus;
    }

    public TripState getTripState() {
        return tripState;
    }

    public void setTripState(TripState tripState) {
        this.tripState = tripState;
    }
    public void setTripStatus(TripStatus tripStatus) {
        this.tripStatus = tripStatus;
    }

    // --- Builder pattern --------
    public static class TripBuilder {
        private final String id;
        private Rider rider;
        // driver get notification of this trip and accept or reject that trip
        private Location pickupLocation;
        private Location dropOffLocation;
        private double fare;

        public TripBuilder(){
            this.id = UUID.randomUUID().toString();
        }

        public TripBuilder setFare(double fare) {
            this.fare = fare;
            return this;
        }

        public TripBuilder setDropOffLocation(Location dropOffLocation) {
            this.dropOffLocation = dropOffLocation;
            return this;
        }

        public TripBuilder setPickupLocation(Location pickupLocation) {
            this.pickupLocation = pickupLocation;
            return this;
        }

        public TripBuilder setRider(Rider rider) {
            this.rider = rider;
            return this;
        }

        public Trip build(){
            // basic check 
            if(rider == null || pickupLocation == null || dropOffLocation == null){
                throw new IllegalStateException("Rider, pickup, and dropoff locations are required to build a trip.");
            }
            return new Trip(this);
        }
        
    }
}
