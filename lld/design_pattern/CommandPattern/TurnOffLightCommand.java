package CommandPattern;

public class TurnOffLightCommand implements Command {
    protected Light light;

    public TurnOffLightCommand(Light light){
        this.light = light;
    }

    public void execute(){
        this.light.turnOff();
    }
}
