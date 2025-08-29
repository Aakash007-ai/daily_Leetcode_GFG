package shreyansh_jain.decorator_design_pattern.ToppingsDecorator;

import shreyansh_jain.decorator_design_pattern.BasePizza.BasePizza;

public class ExtraCheeseDecorator extends BasePizza{
    BasePizza basePizza;

    ExtraCheeseDecorator(BasePizza basePizza){
        this.basePizza = basePizza;
    }

    public Integer price() {
        return this.basePizza.price() + 20;
    }
    
}
