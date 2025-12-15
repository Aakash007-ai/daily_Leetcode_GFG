package CommandPattern;

public class TurnOnLightCommand implements Command {
    protected Light light;

    public TurnOnLightCommand(Light light){
        this.light = light;
    }

    public void execute(){
        this.light.turnOn();
    }
}