package javaLang.DecoratorDesign;

public class MargheritaPizza extends BasePizza {

    public int cost() {
        System.out.println("Margherita base Pizza");
        return 10;
    }
    
}
