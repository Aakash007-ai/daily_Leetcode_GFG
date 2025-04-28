package javaLang.solid.LiskovGood;

public class Bicycle extends Vehicle {
    @Override
    public Integer getNumberOfWheels (){
        return 2;
    }
}
