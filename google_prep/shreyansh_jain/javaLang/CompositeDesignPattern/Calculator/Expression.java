package javaLang.CompositeDesignPattern.Calculator;

public class Expression implements AirthmeticExpression {
    AirthmeticExpression left;
    AirthmeticExpression right;
    Operation operation;
    
    public Expression(AirthmeticExpression left, AirthmeticExpression right, Operation operation){
        this.left = left;
        this.right = right;
        this.operation = operation;
    }

    public int evaluate(){
        int value = 0;
        switch(operation){
            case ADD:
                value =  left.evaluate() + right.evaluate();
                break;
            case SUBTRACT:
                value =  left.evaluate() - right.evaluate();
                break;
            case MULTIPLY:
                value =  left.evaluate() * right.evaluate();
                break;
            case DIVIDE:
                value =  left.evaluate() / right.evaluate();
                break;

            default:
                System.out.println("Invalid operation");
                break;
        }
        System.out.println("Evaluating: " + left.evaluate() + " " + operation + " " + right.evaluate() + " = " + value);
        return value;
    }
}
