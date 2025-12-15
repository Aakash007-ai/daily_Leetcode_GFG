package visitor_design_pattern;

public class VisitorPatternExample {
    public static void main(String[] args){
        Shape circle = new Circle(5);
        Shape rectangle = new Rectangle(4, 6);

        ShapeVisitor areaCalculator = new AreaCalculator();

        // Calculating area of shapes
        circle.accept(areaCalculator);
        rectangle.accept(areaCalculator);

    }
}

/**
 * Shape interface represent the Element
 * Circle and Rectangle are Concrete Elements that can accept a visitor
 * Shape Visitor defines the Visitor interface and Area calculator is a Concrete Visitor that calculate the area of the shapes
 * 
 * this allows us to add new operations (e.g. parameters) by simply creating a new visitor , without modifying the existing Circle or Rectangle classes
 * 
 * 
 */


 /**
  * key difference with facade
  Visitor Pattern Allows addding operations to classes without changing their structure,  promoting flexibility by separating algorithms from the objects they operate on
  */

  /**
   * both patterns helps in different scenarios Facade is about simplifying access to a complex system, while Visitor is about adding functionality to a system without changing its classes
   */