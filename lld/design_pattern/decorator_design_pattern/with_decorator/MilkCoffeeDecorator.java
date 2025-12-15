package decorator_design_pattern.with_decorator;

public class MilkCoffeeDecorator extends CoffeeDecorator {
    public MilkCoffeeDecorator(Coffee customCoffee){
        super(customCoffee);
    }

    public double cost(){
        return coffee.cost() + 3; // check what cause problem when we use this.cost() or this.description()
    }

    public String description(){
        return coffee.description() + " + " + "Milk";
    }
}
