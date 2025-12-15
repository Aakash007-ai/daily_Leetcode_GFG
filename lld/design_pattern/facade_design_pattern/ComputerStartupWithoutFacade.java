package facade_design_pattern;

public class ComputerStartupWithoutFacade {
    public static void main(String[] args){
        CPU cpu = new CPU();
        Memory memory = new Memory();
        HardDrive hardDrive = new HardDrive();

        cpu.freeze();
        byte[] bootData = hardDrive.read(100, 512);
        memory.load(100, bootData);

        cpu.jump(100);
        cpu.execute();
    }
}
