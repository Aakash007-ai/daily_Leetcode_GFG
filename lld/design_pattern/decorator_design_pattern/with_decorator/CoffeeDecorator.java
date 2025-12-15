package decorator_design_pattern.with_decorator;

public abstract class CoffeeDecorator extends  Coffee {
    protected Coffee coffee;

    public CoffeeDecorator(Coffee coffee){
        this.coffee = coffee;
    }

    public abstract String description();
}
