package GetSdeReady.JavaDoubts;

import GetSdeReady.JavaDoubts.interfaces.ParkingSpot;


// initialize map with different empty value, in constructor itself else give null by default
// When initializaing value by Constructor inject try to differ the name, big as usual , small by injection -- ease in assigning and finding issue

public class Main {
    public static void main(String[] args) throws Exception {
        ParkingSpotEnum type1 = ParkingSpotEnum.COMPACT;
        
        ParkingSpot compactParkingSpot = (ParkingSpot) type1.getParkingSpot().getConstructor(int.class, int.class).newInstance(3, 4);
        System.out.println("Parking Spot Floor: " + compactParkingSpot.getFloor());
        // ParkingSpot compactParkingSpot = (ParkingSpot) type1.getParkingSpot().getConstructor(int.class,int.class).newInstance(3, 4);
        // System.out.println("Normal Enum" + " " + compactParkingSpot.getFloor());

        // boolean value = ParkingSpotEnum.COMPACT == type1 ? true : false;
    }
}
