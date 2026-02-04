package ParkingLot.dto.vehicle;

import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.enums.ParkingSpotEnum;

public abstract class Vehicle {
    private ParkingSpotEnum parkingSpotType;

    public Vehicle(ParkingSpotEnum parkingSpotType){
        this.parkingSpotType = parkingSpotType;
    }

    public ParkingSpotEnum getParkingSpotType(){
        return this.parkingSpotType;
    }

}
