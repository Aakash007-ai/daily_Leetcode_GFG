package javaLang.solid.LiskovBad;

public class Bicycle extends Vehicle{
    @Override
    public Boolean hasEngine (){
        return null;
    }
}
