package Practice.RideSharingService.entities;

import Practice.RideSharingService.enums.RideType;

public class Vehicle {
    private final String licenseNumber;
    private final RideType rideType;
    private final String model;

    public Vehicle(String licenseNumber, RideType rideType, String model) {
        this.licenseNumber = licenseNumber;
        this.rideType = rideType;
        this.model = model;
    }

    public String getLicenseNumber() {
        return licenseNumber;
    }

    public RideType getRideType() {
        return rideType;
    }

    public String getModel() {
        return model;
    }
}
