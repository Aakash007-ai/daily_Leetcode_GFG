package ParkingLot.services;

import ParkingLot.dto.DisplayBoard;
import ParkingLot.enums.ParkingSpotEnum;
import ParkingLot.interfaces.DisplayboardService;

public class DisplayBoardServiceImpl implements DisplayboardService{

    @Override
    public void updateDisplayboard(ParkingSpotEnum parkingSpotEnum, int change) {
        int prevCount = DisplayBoard.getDisplayBoardInstance().getFreeParkingSpot().get(parkingSpotEnum);
        DisplayBoard.getDisplayBoardInstance().getFreeParkingSpot().put(parkingSpotEnum, prevCount+change);
    }

}
