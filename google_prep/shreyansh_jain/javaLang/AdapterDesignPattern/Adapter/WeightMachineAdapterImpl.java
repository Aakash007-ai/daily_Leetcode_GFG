package javaLang.AdapterDesignPattern.Adapter;

import javaLang.AdapterDesignPattern.Adaptee.WeightMachine;

public class WeightMachineAdapterImpl implements WeightMachineAdapter {
    WeightMachine weightMachine;
    public WeightMachineAdapterImpl(WeightMachine weightMachine){
        this.weightMachine = weightMachine;
    }

      public double getWeightinKg(){
        double weightInPound = weightMachine.getWeightInPounds() * 0.45359237;
        return weightInPound;
      }
}
