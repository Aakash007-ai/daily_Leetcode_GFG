package parkingStrategy;

import java.util.List;

import dto.ParkingLot;
import dto.parkingSpot.ParkingSpot;
import enums.ParkingSpotEnum;
import exceptions.SpotNotFoundException;

public class FarthestFirstParkingStrategy implements ParkingStrategy {

    @Override
    public ParkingSpot findParkingSpot(ParkingSpotEnum parkingSpotEnum) throws SpotNotFoundException {
        // TODO Auto-generated method stub
         List<ParkingSpot> parkingSpots = ParkingLot.getInstance().getFreeParkingSpots().get(parkingSpotEnum);
        if(parkingSpots.size() == 0){
            throw new SpotNotFoundException("Spot not found in farthest first strategy");
        }
        
        return parkingSpots.get(parkingSpots.size()-1);
    }

}
