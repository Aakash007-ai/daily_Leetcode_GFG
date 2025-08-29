package shreyansh_jain.decorator_design_pattern;

import shreyansh_jain.decorator_design_pattern.BasePizza.BasePizza;
import shreyansh_jain.decorator_design_pattern.BasePizza.VegDelightPizza;
import shreyansh_jain.decorator_design_pattern.ToppingsDecorator.ExtraCheese;
import shreyansh_jain.decorator_design_pattern.ToppingsDecorator.ExtraCheeseDecorator;

/**
 * Decorator design pattern , 
 * 
 * pizza design , we decorate our pizza with toppings and return pizza
 * 
 * so it follow both has a and have a relationship with itself
 * it follow has a of itself to return to update value , it take itself from 
 * constructor pattern,
 * 
 * it is used to prevent class explosion, 
 * Class explosion means suppose we have a base car,
 * we can add multiple features cars with base car, having multiple permutation of features,
 * in this way we will have multipple classes
 * 
 * so to avoid multiple class we use decorator pattern to prevent from car explosion
 * 
 * so we have a base abstract Main class , from which base class is extended, 
 * then we have multiple decorator classes, which will follow has a and is a realtonship with BasePizza, via constructor injection
 */


public class Main {
    public static void main(String[] args){
        BasePizza vegPizza =  new ExtraCheeseDecorator(new VegDelightPizza());
        System.out.println("BasePizza + ExtraChhese cost "+ vegPizza.price());
    }
}
