package lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern;
import lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern.Strategy.SportsDriveStrategy;


public class SportsDriveVehicle extends Vehicle{
    
    SportsDriveVehicle(){
        super(new SportsDriveStrategy());
    }
}
