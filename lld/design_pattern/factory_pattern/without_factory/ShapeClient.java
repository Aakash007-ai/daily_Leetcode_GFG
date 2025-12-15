package factory_pattern.without_factory;

public class ShapeClient {
    public static void main(){
        Circle circle1 = new Circle();
        circle1.draw();

        Rectangle rectangle1 = new Rectangle();
        rectangle1.draw();
    }
}
