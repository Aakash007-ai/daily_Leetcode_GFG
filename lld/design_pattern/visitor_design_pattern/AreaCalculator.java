package visitor_design_pattern;

public class AreaCalculator implements ShapeVisitor {
    public void visit(Circle circle){
        double area = Math.PI*Math.pow(circle.getRadius(), 2);
        System.out.println("Circle Area : " + area);
    }

    public void visit(Rectangle rectangle){
        double area = rectangle.getWidth()*rectangle.getHeight();

        System.out.println("Area of rectangle : "+ area);
    }
}
