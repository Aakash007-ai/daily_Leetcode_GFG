package ParkingLot.services;

import ParkingLot.dto.ParkingLot;
import ParkingLot.dto.ParkingTicket;
import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.dto.vehicle.Vehicle;
import ParkingLot.enums.ParkingSpotEnum;
import ParkingLot.exceptions.SpotNotFoundException;
import ParkingLot.interfaces.DisplayboardService;
import ParkingLot.interfaces.ParkingService;
import ParkingLot.strategy.parkingStrategy.NearestFirstParkingStrategy;
import ParkingLot.strategy.parkingStrategy.ParkingStrategy;

public class ParkingServiceImpl implements ParkingService {
    private DisplayboardService displayboardService = new DisplayBoardServiceImpl();

    public ParkingTicket entry(Vehicle vehicle){
        ParkingStrategy parkingStrategy = new NearestFirstParkingStrategy();
        try{
            ParkingSpot parkingSpot = parkingStrategy.find(vehicle.getParkingSpotType());
            ParkingTicket parkingTicket = new ParkingTicket(vehicle, parkingSpot);
            displayboardService.updateDisplayboard(vehicle.getParkingSpotType(), -1);
            ParkingLot.getParkingLotInstance().getFreeParkingSpot().get(vehicle.getParkingSpotType()).remove(parkingSpot);
            ParkingLot.getParkingLotInstance().getOccupiedParkingSpot().get(vehicle.getParkingSpotType()).add(parkingSpot);
            return parkingTicket;
        }catch(SpotNotFoundException e){
            System.out.println("ParkingEntry Error : " + e.getMessage());
            return null;
        }
    }

    @Override
    public int exit(ParkingTicket ticket) {
        ParkingSpotEnum parkingSpotEnum = ticket.getVehicle().getParkingSpotType();
        ParkingLot.getParkingLotInstance().getOccupiedParkingSpot().get(parkingSpotEnum).remove(ticket.getParkingSpot());
        ParkingLot.getParkingLotInstance().getFreeParkingSpot().get(parkingSpotEnum).add(ticket.getParkingSpot());
        displayboardService.updateDisplayboard(parkingSpotEnum, -1);
        return ticket.calculateCost();
    }
}
