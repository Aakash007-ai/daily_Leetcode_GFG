package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.factory_pattern;


/**
 * whenever we have to create something based on some condition it is called Factory Pattern
 * 
 * Factory Pattern is a creational design pattern
 * factory pattern is used when based on conditional basis, we create/generate object
 * 
 * e.g. we have a shape interface have a draw method , and we create class implementing this shape, (Circle, Rectangle, Square)
 * and we have a main ShapeFactory class which gnerate shape based on condition
 * 
 * 
 * Abstract Factory
 * it is factory of factory 
 */

public class Main {
    public static void main(){
        
        Shape circle = new ShapeFactory().getShape("Circle");
        circle.draw();

    }    
}
