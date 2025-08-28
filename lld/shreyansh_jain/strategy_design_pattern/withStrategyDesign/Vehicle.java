package shreyansh_jain.strategy_design_pattern.withStrategyDesign;

import shreyansh_jain.strategy_design_pattern.withStrategyDesign.strategy.DriveStrategy;

public abstract class Vehicle {
    private DriveStrategy driveStrategy;

    Vehicle(DriveStrategy strategy){
        this.driveStrategy = strategy;
    }

    public void drive(){
        this.driveStrategy.drive();
    }
}