package lld.shrayansh_jain_ytb.decorator_design_pattern;

public class ExtraCheese extends ToppingsDecorator{
    BasePizza pizza;
    public ExtraCheese(BasePizza pizza){
        this.pizza=pizza;
    }
    @Override
    public int cost(){
        return this.pizza.cost()+20;
    }
}
