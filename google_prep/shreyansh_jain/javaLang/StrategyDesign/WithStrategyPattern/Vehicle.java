package javaLang.StrategyDesign.WithStrategyPattern;

import javaLang.StrategyDesign.WithStrategyPattern.Strategy.DriveStrategy;

public class Vehicle {
    DriveStrategy driveStrategy;
    
    Vehicle(DriveStrategy driveObject){
        this.driveStrategy = driveObject;
    }

    public void drive(){
        driveStrategy.drive();
    }
}
