package lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern;

import lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern.Strategy.DriveStrategy;

//at runtime we can change the algorithm
public class Vehicle {
    DriveStrategy driveObj;

    //this is known as constructor injection
    Vehicle(DriveStrategy driveobj){
        this.driveObj = driveobj;//we assign which type of strategy we want to use
    }

    public void drive(){
        driveObj.drive();
    }
}
