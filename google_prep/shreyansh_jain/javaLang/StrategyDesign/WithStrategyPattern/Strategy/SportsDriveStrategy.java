package javaLang.StrategyDesign.WithStrategyPattern.Strategy;

public class SportsDriveStrategy implements DriveStrategy {
    public void drive(){
        System.out.println("Sports Drive Strategy");
    }
}
