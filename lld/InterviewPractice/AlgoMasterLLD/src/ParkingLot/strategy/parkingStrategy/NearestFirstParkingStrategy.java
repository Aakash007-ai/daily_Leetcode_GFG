package ParkingLot.strategy.parkingStrategy;

import java.util.List;

import ParkingLot.dto.ParkingLot;
import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.enums.ParkingSpotEnum;
import ParkingLot.exceptions.SpotNotFoundException;

public class NearestFirstParkingStrategy implements ParkingStrategy{
    
    @Override
    public ParkingSpot find(ParkingSpotEnum parkingSpotEnum) throws SpotNotFoundException {
        // from parking lot find the nearest first 
        List<ParkingSpot> parkingSpots = ParkingLot.getParkingLotInstance().getFreeParkingSpot().get(parkingSpotEnum);
        if(parkingSpots.size() == 0){
            throw new SpotNotFoundException("ParkingSpot Not Found");
        }
        return parkingSpots.get(0);
    }

}
