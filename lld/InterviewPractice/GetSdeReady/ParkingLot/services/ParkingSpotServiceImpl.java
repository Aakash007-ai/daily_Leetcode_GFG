package services;

import java.lang.reflect.InvocationTargetException;

import dto.ParkingLot;
import dto.parkingSpot.ParkingSpot;
import enums.ParkingSpotEnum;
import interfaces.DisplayService;
import interfaces.ParkingSpotService;

public class ParkingSpotServiceImpl implements ParkingSpotService {
    DisplayService displayService = new DisplayServiceImpl();

    @Override
    public ParkingSpot create(ParkingSpotEnum parkingSpotEnum, int floor) {
        try {
            ParkingSpot parkingSpot = (ParkingSpot) parkingSpotEnum.getParkingSpot().getConstructor(int.class).newInstance(floor);
            ParkingLot.getInstance().getFreeParkingSpots().get(parkingSpotEnum).add(parkingSpot);
            displayService.update(parkingSpotEnum, 1);
            return parkingSpot;
        } catch (InstantiationException | IllegalAccessException | IllegalArgumentException
                | InvocationTargetException | NoSuchMethodException | SecurityException e) {
            throw new RuntimeException();
        } 
    }

}
