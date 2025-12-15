package decorator_design_pattern.without_decorator;

public class MilkCoffee implements Coffee {
    
    public void description(){
        System.out.println("Coffee with milk");
    }

    public double cost(){
        return 5+1;
    }
}
