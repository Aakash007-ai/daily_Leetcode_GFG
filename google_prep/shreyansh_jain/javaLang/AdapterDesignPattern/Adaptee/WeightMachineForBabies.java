package javaLang.AdapterDesignPattern.Adaptee;

public class WeightMachineForBabies implements WeightMachine {

    @Override
    public double getWeightInPounds() {
        return 10.0; // Example weight in pounds for babies
    }
    
}
