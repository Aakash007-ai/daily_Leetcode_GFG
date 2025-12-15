package interfaces;

import dto.ParkingTicket;
import dto.vehicle.Vehicle;
import exceptions.InvalidTicketException;

public interface ParkingServices {
    ParkingTicket entry(Vehicle vehicle) ;
    int exit(ParkingTicket parkingTicket, Vehicle vehicle) throws InvalidTicketException;
    void addWash(ParkingTicket parkingTicket);
}
