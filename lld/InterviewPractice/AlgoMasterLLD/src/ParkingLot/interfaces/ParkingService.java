package ParkingLot.interfaces;

import ParkingLot.dto.ParkingTicket;
import ParkingLot.dto.vehicle.Vehicle;

public interface ParkingService {
    public ParkingTicket entry(Vehicle vehicle);
    public int exit(ParkingTicket ticket);   
}
