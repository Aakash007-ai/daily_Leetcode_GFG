package decorator_design_pattern.without_decorator;

public class MilkSugarCoffee implements Coffee {
    
    public void description(){
        System.out.println("Milk coffee with sugar");
    }

    public double cost(){
        return 8;
    }
}
