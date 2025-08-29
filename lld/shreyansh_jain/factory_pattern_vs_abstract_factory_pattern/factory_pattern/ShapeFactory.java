package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.factory_pattern;

public class ShapeFactory {
    Shape getShape(String shape){
        switch (shape) {
            case "Circle":
                return new Circle();
            case "Square":
            return new Square();
            default:
            return null;
        }
    }
}
