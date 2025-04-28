package javaLang.solid.LiskovBad;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Vehicle vehicle = new Vehicle();
        Car car = new Car();
        MotoCycle motoCycle = new MotoCycle();

        List<Vehicle> vehicleList = new ArrayList<>();
        vehicleList.add(car);
        vehicleList.add( motoCycle);
        vehicleList.add(new Bicycle());

        for(Vehicle vehicle: vehicleList){
            System.out.println("Number of wheels: " + vehicle.getNumberOfWheels());
            System.out.println("Has engine: " + vehicle.hasEngine());
        }
    }
}


// here bicucle return null for hasEngine and 0 for getNumberOfWheels
// this is not a good design as it breaks the Liskov substitution principle

// sub class narrow down the functionality of the parent class
// to resovle this in Parent class we have very generic method
