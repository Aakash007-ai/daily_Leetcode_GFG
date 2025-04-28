package javaLang.solid.LiskovGood;

import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String[] args){
        List<Vehicle> vehcilelist = new ArrayList<>();
        vehcilelist.add(new Bicycle());

        vehcilelist.add(new Car());

        for(Vehicle vehicle: vehcilelist){
            System.out.println("Number of wheels: " + vehicle.getNumberOfWheels());
            // System.out.println("Has engine: " + vehicle.hasEngine()); //gives error at compile time
        }

        List<EngineVehicle> engineVehicles = new ArrayList<>();
        engineVehicles.add(new Car());
        // engineVehicles.add(new Bicycle())
    }
}
