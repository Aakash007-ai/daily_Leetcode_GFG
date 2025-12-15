package facade_design_pattern;

public class ComputerStartupWithFacade {
    public static void main(String[] args){
        ComputerFacade computer = new ComputerFacade();
        computer.start();
    }
}
