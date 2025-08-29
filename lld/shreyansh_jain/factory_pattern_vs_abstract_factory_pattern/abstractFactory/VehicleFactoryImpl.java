package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory;

import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.NormalFactory.NormalFactory;

public class VehicleFactoryImpl implements VehicleFactory {
    public CarsFactory geFactory(String carsCategory) {
        switch(carsCategory){
            case "Noramal" : 
            return new NormalFactory();
            case "Luxuary":
            default:
            return null;
        }
    }
    
}
