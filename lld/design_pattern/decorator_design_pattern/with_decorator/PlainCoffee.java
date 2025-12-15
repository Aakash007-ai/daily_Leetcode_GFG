package decorator_design_pattern.with_decorator;

public class PlainCoffee extends Coffee {
    
    public String description(){
        System.out.println("Plain Coffee");
        return "Plain coffee";
    }

    public double cost(){
        return 10;
    }
}
