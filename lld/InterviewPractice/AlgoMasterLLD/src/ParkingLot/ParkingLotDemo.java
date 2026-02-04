package ParkingLot;

import ParkingLot.dto.ParkingTicket;
import ParkingLot.dto.vehicle.Car;
import ParkingLot.dto.vehicle.Vehicle;
import ParkingLot.interfaces.ParkingService;
import ParkingLot.interfaces.PaymentService;
import ParkingLot.services.ParkingServiceImpl;
import ParkingLot.services.PaymentServiceImpl;

public class ParkingLotDemo {
    public static void run(){
        ParkingService parkingService = new ParkingServiceImpl();
        PaymentService paymentService = new PaymentServiceImpl();
        Vehicle car1 = new Car();
        
        ParkingTicket parkingTicket = parkingService.entry(car1);

        int cost = parkingService.exit(parkingTicket);
        paymentService.acceptCash(cost);

        parkingService.exit(parkingTicket);
        
    }
}
