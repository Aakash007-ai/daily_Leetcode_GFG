package shreyansh_jain.strategy_design_pattern.withStrategyDesign;

import shreyansh_jain.strategy_design_pattern.withStrategyDesign.strategy.SportsStrategy;

public class SportsVehicle extends Vehicle {

    SportsVehicle(){
        super(new SportsStrategy());
    }
    
}
