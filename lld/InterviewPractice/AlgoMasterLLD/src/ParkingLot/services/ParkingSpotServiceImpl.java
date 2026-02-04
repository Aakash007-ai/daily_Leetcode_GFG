package ParkingLot.services;

import java.lang.reflect.InvocationTargetException;

import ParkingLot.dto.ParkingLot;
import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.enums.ParkingSpotEnum;
import ParkingLot.interfaces.DisplayboardService;
import ParkingLot.interfaces.ParkingSpotService;

public class ParkingSpotServiceImpl implements ParkingSpotService {
    private ParkingLot parkingLotInstance = ParkingLot.getParkingLotInstance();
    private DisplayboardService displayboardService = new DisplayBoardServiceImpl();
    
    
    public void createParkingSpot(ParkingSpotEnum parkingSpotEnum, int floor){
        try {
            ParkingSpot parkingSpot = (ParkingSpot) parkingSpotEnum.getParkingSpot().getConstructor(int.class, int.class).newInstance(40,floor);
            parkingLotInstance.getFreeParkingSpot().get(parkingSpotEnum).add(parkingSpot);
            displayboardService.updateDisplayboard(parkingSpotEnum, 1);
        } catch (InstantiationException | IllegalAccessException | IllegalArgumentException | InvocationTargetException
                | NoSuchMethodException | SecurityException e) {
            e.printStackTrace();
        }

    }
}
