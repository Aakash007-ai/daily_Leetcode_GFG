package Practice.PParkingLot.dto.vehicle;

import ParkingLot.enums.ParkingSpotEnum;

/**
 * now here we want an enum which will give class of that type
 */
public class Car extends Vehicle{
    public Car(){
        super(ParkingSpotEnum.COMPACT);
    }
}
