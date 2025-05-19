package javaLang.CompositeDesignPattern.Calculator;

public class Number implements AirthmeticExpression {
    int value;

    public Number(int value){
        this.value = value;
    }

    public int evaluate(){ //its a leaf node so we just return it in function
        return value;
    }
}
