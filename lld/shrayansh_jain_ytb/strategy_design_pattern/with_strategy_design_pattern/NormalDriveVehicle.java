package lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern;

import lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern.Strategy.NormalDriveStrategy;

public class NormalDriveVehicle extends Vehicle{
    
    NormalDriveVehicle(){
        super(new NormalDriveStrategy());
    }
}
