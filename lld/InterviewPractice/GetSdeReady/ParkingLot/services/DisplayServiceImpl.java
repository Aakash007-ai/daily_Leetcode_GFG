package services;

import dto.DisplayBoard;
import dto.ParkingEvent;
import enums.ParkingEventType;
import enums.ParkingSpotEnum;
import interfaces.DisplayService;
import interfaces.Observer;

public class DisplayServiceImpl implements DisplayService, Observer {

    @Override
    public void update(ParkingSpotEnum parkingSpotEnum, int change) {
        int currentCount = DisplayBoard.getInstance().getFreeParkingSpot().get(parkingSpotEnum);
        int nextCount = currentCount + change;
        DisplayBoard.getInstance().getFreeParkingSpot().put(parkingSpotEnum, nextCount);
    }

    @Override
    public void update(ParkingEvent event) {
        int currentCount = DisplayBoard.getInstance().getFreeParkingSpot().get(event.getParkingSpotEnum());
        int changes = 0;
        if(event.getEventType().equals(ParkingEventType.ENTRY)){
            changes = -1;
        }else{
            changes = 1;
        }

        int newCount = currentCount + changes;
        DisplayBoard.getInstance().getFreeParkingSpot().replace(event.getParkingSpotEnum(),newCount);
    }
    
}
