package ParkingLot.dto;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.enums.ParkingSpotEnum;

public class ParkingLot {
    private String name;
 
    private List<EntrancePanel> entrancePanels;
    private List<ExitPanel> exitPanels;
    private Map<ParkingSpotEnum, List<ParkingSpot>> freeParkingSpot;

    private Map<ParkingSpotEnum, List<ParkingSpot>> occupiedParkingSpot;

    private DisplayBoard displayBoard;
    private static ParkingLot parkingLot = null;

    private ParkingLot(){
        displayBoard = DisplayBoard.getDisplayBoardInstance();
        
        freeParkingSpot.put(ParkingSpotEnum.LARGE, new ArrayList<>());
        freeParkingSpot.put(ParkingSpotEnum.COMPACT, new ArrayList<>());
        freeParkingSpot.put(ParkingSpotEnum.MINI, new ArrayList<>());

        occupiedParkingSpot.put(ParkingSpotEnum.LARGE, new ArrayList<>());
        occupiedParkingSpot.put(ParkingSpotEnum.COMPACT, new ArrayList<>());
        occupiedParkingSpot.put(ParkingSpotEnum.MINI, new ArrayList<>());

    }

    public static ParkingLot getParkingLotInstance(){
        if(parkingLot == null){
            parkingLot = new ParkingLot();
        }
        return parkingLot;
    }

    public Map<ParkingSpotEnum, List<ParkingSpot>> getFreeParkingSpot() {
        return freeParkingSpot;
    }

    public void setFreeParkingSpot(Map<ParkingSpotEnum, List<ParkingSpot>> freeParkingSpot) {
        this.freeParkingSpot = freeParkingSpot;
    }

    
    public Map<ParkingSpotEnum, List<ParkingSpot>> getOccupiedParkingSpot() {
        return occupiedParkingSpot;
    }

    public void setOccupiedParkingSpot(Map<ParkingSpotEnum, List<ParkingSpot>> occupiedParkingSpot) {
        this.occupiedParkingSpot = occupiedParkingSpot;
    }

}
