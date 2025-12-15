package factory_pattern.with_factory;

public class ShapeFactory {
    public Shape getShape(String shapeType){
        if(shapeType.equals("circle")){
            return new Circle();
        }else{
            return null;
        }
    }
}
