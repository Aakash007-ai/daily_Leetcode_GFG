package visitor_design_pattern;

public class Rectangle implements Shape {
    private double width, height ;

    public Rectangle(double width, double height){
        this.width = width;
        this.height = height;
    }

    public double getWidth(){
        return this.width;
    }

    public double getHeight(){
        return this.height;
    }
    
    public void accept(ShapeVisitor visitor){
        visitor.visit(this);
    }
}
