package shreyansh_jain.decorator_design_pattern.ToppingsDecorator;

import shreyansh_jain.decorator_design_pattern.BasePizza.BasePizza;

public class MushroomDecorator extends BasePizza {
    BasePizza basePizza;

    MushroomDecorator(BasePizza basePizza){
        this.basePizza = basePizza;
    }

    public Integer price(){
        return this.basePizza.price() + 10;
    }
    
}
