package javaLang.StrategyDesign.WithStrategyPattern;
import javaLang.StrategyDesign.WithStrategyPattern.Strategy.NormalDriveStrategy;

public class NormalDriveVehicle extends Vehicle {
    
    NormalDriveVehicle(){
        super(new NormalDriveStrategy());
    }
    
} // now it will have drive method of having normal drive strategy
