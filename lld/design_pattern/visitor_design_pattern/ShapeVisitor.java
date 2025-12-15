package visitor_design_pattern;

public interface ShapeVisitor {
    void visit(Circle circle);
    void visit(Rectangle rectangle);
}
