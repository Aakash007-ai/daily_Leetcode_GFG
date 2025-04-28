package javaLang.solid.LiskovBad;

public class Car extends Vehicle {

    @Override
    public Integer getNumberOfWheels() {
        return 4;
    }
}
