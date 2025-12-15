package decorator_design_pattern.without_decorator;

public class NormalCoffee implements Coffee{
    public void description(){
        System.out.println("Plain Coffee");
    }
    
    public double cost(){ //Integer
        return 10;
    }
}
