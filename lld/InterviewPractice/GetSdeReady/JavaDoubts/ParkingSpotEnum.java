package GetSdeReady.JavaDoubts;

import GetSdeReady.JavaDoubts.interfaces.*;

public enum ParkingSpotEnum {
    COMPACT(Compact.class),
    MINI(Mini.class),
    LARGE(Large.class);

    private Class parkingSpot;
    
    ParkingSpotEnum(Class x) {
        //TODO Auto-generated constructor stub
        System.out.println("Parking Spot Enum called");
        this.parkingSpot = x;
    }

    public Class getParkingSpot(){
        return parkingSpot;
    }
}