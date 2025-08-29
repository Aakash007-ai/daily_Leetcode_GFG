package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.NormalFactory;

import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.CarsFactory;
import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.HatchBackVehicle;
import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.NormalVehicle;
import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.Vehicle;

public class NormalFactory implements CarsFactory {
    public Vehicle getVehicle(String vehicle){
        switch (vehicle) {
            case "Normal":
                return new NormalVehicle();
            case "Hatchback":
            return new HatchBackVehicle();
            default:
                return null;
        }
    }
}
