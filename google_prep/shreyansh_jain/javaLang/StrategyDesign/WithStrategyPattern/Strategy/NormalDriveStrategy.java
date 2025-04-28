package javaLang.StrategyDesign.WithStrategyPattern.Strategy;

public class NormalDriveStrategy implements DriveStrategy {
    public void drive(){
        System.out.println("Normal drive strategy");
    }
}
