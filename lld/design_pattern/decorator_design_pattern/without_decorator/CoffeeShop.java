package decorator_design_pattern.without_decorator;

public class CoffeeShop {
    public static void main(){
        Coffee milkCoffee = new MilkCoffee();
        Coffee milkSugarCoffee = new MilkSugarCoffee();

        milkCoffee.description();
        milkSugarCoffee.description();
    }
}

/**
 * So here for all type of coffee have to create that coffee class and any flavour we have to create that class
 * 
 * so we have to create combination of all type of coffee on addition to that flavour
 */