package visitor_design_pattern;

public class Circle implements Shape {

    private double radius;

    public Circle(double radius){
        this.radius = radius;
    }

    public double getRadius(){
        return this.radius;
    }

    public void accept(ShapeVisitor visitor){
        visitor.visit(this);
    }
}
