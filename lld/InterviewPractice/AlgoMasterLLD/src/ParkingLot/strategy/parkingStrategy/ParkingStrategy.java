package ParkingLot.strategy.parkingStrategy;

import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.enums.ParkingSpotEnum;
import ParkingLot.exceptions.SpotNotFoundException;

public interface ParkingStrategy {
    public ParkingSpot find(ParkingSpotEnum parkingSpotEnum) throws SpotNotFoundException;
}
