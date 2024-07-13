package lld.shrayansh_jain_ytb.strategy_design_pattern.with_strategy_design_pattern.Strategy;

public class NormalDriveStrategy implements DriveStrategy {
    @Override
    public void drive(){
        System.out.println("normal drive strategy");
    }
}
