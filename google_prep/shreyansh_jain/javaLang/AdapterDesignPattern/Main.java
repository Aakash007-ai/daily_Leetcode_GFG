package javaLang.AdapterDesignPattern;

import javaLang.AdapterDesignPattern.Adaptee.WeightMachine;
import javaLang.AdapterDesignPattern.Adaptee.WeightMachineForBabies;
import javaLang.AdapterDesignPattern.Adapter.WeightMachineAdapter;
import javaLang.AdapterDesignPattern.Adapter.WeightMachineAdapterImpl;

// import javaLang.AdapterDesignPattern.Adaptee.WeightMachine;
// import javaLang.AdapterDesignPattern.Adapter.WeightMachineAdapter;

public class Main {
    public static void main(String args[]){
        // Create an instance of the WeightMachine class
        WeightMachine weightMachine = new WeightMachineForBabies();
        // Create an instance of the WeightMachineAdapterImpl class
        WeightMachineAdapter weightMachineAdapter = new WeightMachineAdapterImpl(weightMachine);
        
        // Get the weight in kilograms using the adapter
        double weightInKg = weightMachineAdapter.getWeightinKg();
        
        // Print the weight in kilograms
        System.out.println("Weight in kg: " + weightInKg);
    }
}
