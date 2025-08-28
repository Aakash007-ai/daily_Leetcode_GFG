package shreyansh_jain.strategy_design_pattern.without_strategy;
/**
 * in strategy design pattern ,
 * there is a class A (has a drive method, which will explained by its child class) and its mulitple subclass B,  
 * most sublasses have similar methods drive for some groups, but in fututre there can be mulitple strategy
 * so in traditional method we have to write same code for multiple child class. this lead to multiple code duplicacy
 * 
 * to overcome above problem we use Strategy design pattern
 */
public class Main {
    public static void main(String[] args){
        Vehicle normaVehicle = new NormalVehicle();
        Vehicle sportsVehicle = new SportsVehicle();

        normaVehicle.drive();
        sportsVehicle.drive();
    }
    
}
