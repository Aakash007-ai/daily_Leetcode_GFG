package CommandPattern;

/**
 * Mediator : Foucses on reducing direct communication between objects by introducing a mediator that controls the interaction
 * 
 * Commans : Encapsulate a request as an object, allowing it to be parameterized, delayed or even undone
 */
public class CommandPatternExample {
    public static void main(String[] args){
        Light livingRoomLight =  new Light();

        Command turnOn = new TurnOnLightCommand(livingRoomLight);
        Command turnOff = new TurnOffLightCommand(livingRoomLight);

        RemoteControl remote = new RemoteControl();


        remote.setCommand(turnOn);
        remote.pressButton();

        remote.setCommand(turnOff);
        remote.pressButton();
    }
}
