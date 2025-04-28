package javaLang.StrategyDesign.WithStrategyPattern;

public class Main {
    public static void main(String args[]){
        Vehicle vehicle = new NormalDriveVehicle();
        vehicle.drive();
    }
}
