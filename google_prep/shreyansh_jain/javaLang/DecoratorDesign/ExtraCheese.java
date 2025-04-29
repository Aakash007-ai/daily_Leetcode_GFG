package javaLang.DecoratorDesign;
public class ExtraCheese extends ToppingDecorator {
    protected BasePizza basePizza;

    public ExtraCheese(BasePizza basePizza){
        this.basePizza = basePizza;
    }

    @Override
    public int cost(){
        System.out.println("Extra Cheese added");
        return basePizza.cost() + 2; // Adding the cost of extra cheese
    }
}