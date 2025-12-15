package dto.parkingSpot.spotDecorator;

import dto.parkingSpot.*;

public abstract class SpotDecorator extends ParkingSpot {
    protected ParkingSpot parkingSpot;

    public SpotDecorator(ParkingSpot parkingSpot){
        this.parkingSpot = parkingSpot;
    }
}
