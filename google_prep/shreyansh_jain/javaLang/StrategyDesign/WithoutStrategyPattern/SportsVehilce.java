package javaLang.StrategyDesign.WithoutStrategyPattern;

public class SportsVehilce extends Vehicle {
    @Override
    public void drive(){
        System.out.println(
            "Sports vehicle drive strategy"
        );
    }
}
