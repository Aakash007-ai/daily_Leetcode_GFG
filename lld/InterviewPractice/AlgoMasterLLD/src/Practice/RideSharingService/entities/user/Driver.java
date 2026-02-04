package Practice.RideSharingService.entities.user;

import Practice.RideSharingService.entities.Location;
import Practice.RideSharingService.entities.Trip;
import Practice.RideSharingService.entities.Vehicle;
import Practice.RideSharingService.enums.DriverStatus;
import Practice.RideSharingService.observer.TripObserver;

public class Driver extends User implements TripObserver {
    private final Vehicle vehicle; 
    private Location currLocation;
    private DriverStatus status;

    public Driver(String name, String phone, Vehicle vehicle, Location location) {
        super(name, phone);
        this.vehicle = vehicle;
        this.currLocation = location;
        this.status = DriverStatus.ONLINE;
    }

    @Override
    public void onUpdate(Trip trip) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'onUpdate'");
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public Location getCurrLocation() {
        return currLocation;
    }

    public void setCurrLocation(Location currLocation) {
        this.currLocation = currLocation;
    }

    public DriverStatus getDriverStatus() {
        return status;
    }

    public void setDriverStatus(DriverStatus driverStatus) {
        this.status = driverStatus;
    }

}
