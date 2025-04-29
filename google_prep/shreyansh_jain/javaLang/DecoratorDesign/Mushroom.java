package javaLang.DecoratorDesign;

public class Mushroom extends ToppingDecorator{
    protected BasePizza basePizza;
    public Mushroom(BasePizza basePizza) {
        this.basePizza = basePizza;
    }
    
    @Override
    public int cost() {
        System.out.println("Mushroom added");
        return basePizza.cost() + 3; // Adding the cost of mushroom
    }
}
