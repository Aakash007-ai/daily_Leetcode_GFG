package Practice.PParkingLot.enums;

import ParkingLot.dto.parkingSpot.Compact;
import ParkingLot.dto.parkingSpot.Large;
import ParkingLot.dto.parkingSpot.Mini;

public enum ParkingSpotEnum {
    MINI(Mini.class),
    COMPACT(Compact.class),
    LARGE(Large.class);

    private Class parkingSpotType;
    ParkingSpotEnum(Class parkingSpotType) {
        this.parkingSpotType = parkingSpotType;
    }

    public Class getParkingSpot(){
        return parkingSpotType;
    }
}
