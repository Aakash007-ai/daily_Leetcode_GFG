package services;

import java.util.ArrayList;
import java.util.List;

import dto.ParkingEvent;
import dto.ParkingLot;
import dto.ParkingTicket;
import dto.parkingSpot.ParkingSpot;
import dto.parkingSpot.spotDecorator.Wash;
import dto.vehicle.Vehicle;
import enums.ParkingEventType;
import enums.ParkingSpotEnum;
import exceptions.InvalidTicketException;
import exceptions.SpotNotFoundException;
import interfaces.DisplayService;
import interfaces.Observer;
import interfaces.ParkingServices;
import parkingStrategy.ParkingStrategy;

public class ParkingServiceImpl implements ParkingServices {
    ParkingStrategy parkingStrategy;
    ParkingLot parkingLot;
    DisplayService displayService;
    List<Observer> observers;

    public ParkingServiceImpl(ParkingStrategy parkingStrategy){
        this.parkingStrategy = parkingStrategy;
        this.parkingLot = ParkingLot.getInstance();
        this.displayService = new DisplayServiceImpl();
        observers = new ArrayList<>();
    }

    public void addObservers(Observer observer){
        observers.add(observer);
    }

    public void notifyObservers(ParkingEvent event){
        for(Observer observer : observers){
            observer.update(event);
        }
    }

    public void addWash(ParkingTicket parkingTicket){
        parkingTicket.setParkingSpot(new Wash( parkingTicket.getParkingSpot()));
    }

    @Override
    public ParkingTicket entry(Vehicle vehicle) {
        ParkingSpotEnum parkingSpotEnum = vehicle.getParkingSpotEnum();
        List<ParkingSpot> freeParkingSpots = parkingLot.getFreeParkingSpots().get(parkingSpotEnum);
        List<ParkingSpot> occupiedParkingSpots = parkingLot.getOccupiedParkingSpots().get(parkingSpotEnum);
        
        try {
        ParkingSpot parkingSpot = parkingStrategy.findParkingSpot(parkingSpotEnum);

            if(parkingSpot.isFree()){
                synchronized(parkingSpot){
                    if(parkingSpot.isFree()){
                        parkingSpot.setFree(false);
                        freeParkingSpots.remove(parkingSpot);
                        occupiedParkingSpots.add(parkingSpot);
                        ParkingTicket parkingTicket = new ParkingTicket(vehicle, parkingSpot);
                        ParkingEvent parkingEvent = new ParkingEvent(ParkingEventType.ENTRY, parkingSpotEnum);
                        notifyObservers(parkingEvent);
                        return parkingTicket;
                    }
                    return entry(vehicle);
                }
            }
        }catch(SpotNotFoundException e){
            throw new RuntimeException(e);
        }
       return null;
   }

   private void addParkingSpotInFreeList(List<ParkingSpot> parkingSpots, ParkingSpot parkingSpot){
    parkingSpots.add(parkingSpot);
   }

    @Override
    public int exit(ParkingTicket parkingTicket, Vehicle vehicle) throws InvalidTicketException {
        if(parkingTicket.getVehicle().equals(vehicle)){
            ParkingSpot parkingSpot = parkingTicket.getParkingSpot();
            int amount = parkingSpot.getAmount();
            parkingSpot.setFree(true);

            parkingLot.getOccupiedParkingSpots().get(vehicle.getParkingSpotEnum()).remove(parkingSpot);
            addParkingSpotInFreeList(parkingLot.getFreeParkingSpots().get(vehicle.getParkingSpotEnum()), parkingSpot);
            ParkingEvent parkingEvent = new ParkingEvent(ParkingEventType.EXIT, vehicle.getParkingSpotEnum());
            notifyObservers(parkingEvent);
            // displayService.update(vehicle.getParkingSpotEnum(), 1);
            return amount;
        }else{
            throw new InvalidTicketException("Invalid ticket");
        } 
    }
    
}
