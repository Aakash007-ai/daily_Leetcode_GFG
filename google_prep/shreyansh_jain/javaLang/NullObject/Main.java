package javaLang.NullObject;

public class Main {
    public static void main (String args[]){
        Vehicle vehicle = VehicleFactory.getVehicleObject("CAR");
        printVehicleDetails(vehicle);
    }
     public static void printVehicleDetails(Vehicle vehicle) {
        System.out.println("Tank Capacity: " + vehicle.getTankCapacity());
        System.out.println("Seating Capacity: " + vehicle.getSeatingCapacity());
     }
}
