package factory_pattern.with_factory;

public class ShapeClient {
    public static void main(){
        ShapeFactory shapeFactory = new ShapeFactory();

        Shape circle1 = shapeFactory.getShape("circle");

        Shape rectangle = shapeFactory.getShape("rectangle");
    }
}


/**
 * benefit  here we decoiple the object creation from the main method
 * open closed principle, reusability
 * 
 */