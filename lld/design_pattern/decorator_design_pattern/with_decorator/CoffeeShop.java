package decorator_design_pattern.with_decorator;

public class CoffeeShop {
    public static void main(String[] args){
        // Coffee plainCoffee = new PlainCoffee();

        Coffee milkCoffee = new MilkCoffeeDecorator(new PlainCoffee());
        System.out.println("milk coffee cost " + milkCoffee.cost());
        System.out.println("milk coffee description " + milkCoffee.description());
    }
}
