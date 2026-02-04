package Practice.PParkingLot;

import ParkingLot.dto.ParkingTicket;
import ParkingLot.dto.vehicle.Car;
import ParkingLot.dto.vehicle.Vehicle;
import ParkingLot.interfaces.ParkingService;
import ParkingLot.services.ParkingServiceImpl;

public class ParkingLotDemo {
    public static void run(){
        ParkingService parkingService = new ParkingServiceImpl();

        Vehicle car1 = new Car();
        
        ParkingTicket parkingTicket = parkingService.entry(car1);

        int cost = parkingService.exit(parkingTicket);

    }
}
