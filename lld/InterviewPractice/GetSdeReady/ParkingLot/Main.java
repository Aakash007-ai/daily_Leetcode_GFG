
import enums.*;
import exceptions.InvalidTicketException;
import interfaces.*;
import parkingStrategy.FarthestFirstParkingStrategy;
import services.*;
import dto.*;
import dto.parkingSpot.*;
import dto.vehicle.*;

public class Main {
    
    public static void main(String[] args){
        ParkingLot parkingLot = ParkingLot.getInstance();
        ParkingSpotService parkingSpotService = new ParkingSpotServiceImpl();

        ParkingSpot s1 = parkingSpotService.create(ParkingSpotEnum.COMPACT, 0);
        ParkingSpot s2 = parkingSpotService.create(ParkingSpotEnum.COMPACT,0);

        ParkingSpot s3 = parkingSpotService.create(ParkingSpotEnum.LARGE, 0);
        ParkingSpot s4 = parkingSpotService.create(ParkingSpotEnum.LARGE,0);
   
        ParkingSpot s5 = parkingSpotService.create(ParkingSpotEnum.MINI, 0);
        ParkingSpot s6 = parkingSpotService.create(ParkingSpotEnum.MINI, 0);

        Vehicle v1 = new Car();
        Vehicle v2 = new Car();
        
        Vehicle v3 = new Motorbike();
        Vehicle v4 = new Car();

        ParkingServices parkingLotServices = new ParkingServiceImpl(new FarthestFirstParkingStrategy());
        PaymentService paymentService = new PaymentServiceImpl();

        ParkingTicket parkingTicket1 = parkingLotServices.entry(v1);
        parkingLotServices.addWash(parkingTicket1);
        
        try{
            parkingLotServices.exit(parkingTicket1, v1);
            int cost = parkingTicket1.getParkingSpot().getAmount();
            System.out.println("Cost of parking : "+cost);
            paymentService.acceptCash(cost);
        }catch(InvalidTicketException e){
            throw new RuntimeException(e);
        }

        System.out.println("Parking Ticket 1 : "+parkingTicket1);

    }
}
