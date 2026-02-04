package ParkingLot.interfaces;

import ParkingLot.enums.ParkingSpotEnum;

public interface ParkingSpotService {
    public void createParkingSpot(ParkingSpotEnum parkingSpotEnum, int floor);
}
