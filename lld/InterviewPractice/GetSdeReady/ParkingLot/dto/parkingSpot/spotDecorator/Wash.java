package dto.parkingSpot.spotDecorator;

import dto.parkingSpot.ParkingSpot;

public class Wash extends SpotDecorator{

    public Wash(ParkingSpot parkingSpot) {
        super(parkingSpot);
    }

    @Override
    public int getAmount(){
        System.out.println("Parking Spot Amount : " + super.getAmount());
        return super.getAmount() + 30;
    }

}
