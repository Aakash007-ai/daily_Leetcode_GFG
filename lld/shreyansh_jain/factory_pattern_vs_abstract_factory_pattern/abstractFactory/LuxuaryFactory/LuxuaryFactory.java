package shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.LuxuaryFactory;

import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.CarsFactory;
import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.SportsVehicle;
import shreyansh_jain.factory_pattern_vs_abstract_factory_pattern.abstractFactory.Vehicle.Vehicle;

public class LuxuaryFactory implements CarsFactory {
    public Vehicle getVehicle(String vehicle){
        switch (vehicle) {
            case "Sports":
                return new SportsVehicle();
            default:
                return null;
        }
    }
}
