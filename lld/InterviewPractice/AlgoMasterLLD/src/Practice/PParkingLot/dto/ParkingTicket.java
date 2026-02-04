package Practice.PParkingLot.dto;

import java.time.LocalDateTime;
import java.util.concurrent.atomic.AtomicInteger;

import ParkingLot.dto.parkingSpot.ParkingSpot;
import ParkingLot.dto.vehicle.Vehicle;

public class ParkingTicket {
    private int id;
    private Vehicle vehicle;

    private ParkingSpot parkingSpot;

    private LocalDateTime timestamp;
    private AtomicInteger x = new AtomicInteger();

    public ParkingTicket(Vehicle vehicle, ParkingSpot parkingSpot) {
        this.vehicle = vehicle;
        this.parkingSpot = parkingSpot;
        this.id = x.incrementAndGet();
        this.timestamp = LocalDateTime.now();
    }

    public ParkingSpot getParkingSpot() {
        return parkingSpot;
    }

    public void setParkingSpot(ParkingSpot parkingSpot) {
        this.parkingSpot = parkingSpot;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public int calculateCost(){
        return this.parkingSpot.getAmount();
    }

}
