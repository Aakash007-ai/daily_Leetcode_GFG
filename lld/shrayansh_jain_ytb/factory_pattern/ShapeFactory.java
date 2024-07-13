package lld.shrayansh_jain_ytb.factory_pattern;

public class ShapeFactory {
    Shape getShape(String input){
        switch(input){
            case "Rectangle":
                return new Rectangle();
            case "Circle":
                
        }
    }
}
