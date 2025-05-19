package javaLang.CompositeDesignPattern.Calculator;


public class Main {
    public static void main(String args[]) {
        AirthmeticExpression two = new Number(2);
        AirthmeticExpression one = new Number(1);
        AirthmeticExpression seven = new Number(7);

        AirthmeticExpression addEx = new Expression(one, seven, Operation.ADD);
        AirthmeticExpression multiplyEx = new Expression(two, addEx, Operation.MULTIPLY);

        System.out.println("output of expression is ->" + multiplyEx.evaluate());


    }
}
