package dto;
import java.util.HashMap;
import java.util.Map;

import enums.ParkingSpotEnum;

public class DisplayBoard {
    private static DisplayBoard displayBoard = null;
    private static Map<ParkingSpotEnum, Integer> freeParkingSpot;

    private DisplayBoard(){
        freeParkingSpot = new HashMap<>();
        freeParkingSpot.put(ParkingSpotEnum.COMPACT,0);
        freeParkingSpot.put(ParkingSpotEnum.LARGE,0);
        freeParkingSpot.put(ParkingSpotEnum.MINI,0);
    }

    public static DisplayBoard getInstance(){
        if(displayBoard == null){
            displayBoard = new DisplayBoard();
        }
        return displayBoard;
    }

    public Map<ParkingSpotEnum, Integer> getFreeParkingSpot() {
        return freeParkingSpot;
    }
}
