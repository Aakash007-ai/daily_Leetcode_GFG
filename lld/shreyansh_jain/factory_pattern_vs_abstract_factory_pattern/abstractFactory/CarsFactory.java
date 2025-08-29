package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory;

import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.Vehicle;

public interface CarsFactory {
    public Vehicle getVehicle(String vehicle);
    
}
