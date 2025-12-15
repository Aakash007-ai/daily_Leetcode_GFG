package visitor_design_pattern;

public interface Shape {
    void accept(ShapeVisitor visitor);
}

