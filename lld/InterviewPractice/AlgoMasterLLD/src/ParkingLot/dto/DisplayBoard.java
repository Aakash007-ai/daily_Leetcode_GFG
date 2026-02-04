package ParkingLot.dto;

import java.util.HashMap;
import java.util.Map;

import ParkingLot.enums.ParkingSpotEnum;

public class DisplayBoard {
    private static DisplayBoard displayboard;
    private Map<ParkingSpotEnum, Integer> freeParkingSpot = null;

    public void setFreeParkingSpot(Map<ParkingSpotEnum, Integer> freeParkingSpot) {
        this.freeParkingSpot = freeParkingSpot;
    }

    public Map<ParkingSpotEnum, Integer> getFreeParkingSpot() {
        return freeParkingSpot;
    }

    private DisplayBoard(){
        freeParkingSpot = new HashMap<>();
        freeParkingSpot.put(ParkingSpotEnum.LARGE, 0);
        freeParkingSpot.put(ParkingSpotEnum.COMPACT, 0);
        freeParkingSpot.put(ParkingSpotEnum.MINI, 0);
    }

    public static DisplayBoard getDisplayBoardInstance(){
        if(displayboard == null){
            displayboard = new DisplayBoard();
        }

        return  displayboard;
    }

    
}
