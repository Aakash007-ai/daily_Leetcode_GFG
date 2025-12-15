package facade_design_pattern;

public class ComputerFacade {
    private CPU cpu;
    private Memory memory;
    private HardDrive hardDrive;

    public ComputerFacade(){
        this.cpu = new CPU();
        this.memory = new Memory();
        this.hardDrive = new HardDrive();
    }

    public void start(){
        System.out.println("Starting the computer...");
        cpu.freeze();
        byte[] bootData = hardDrive.read(100, 512);
        memory.load(100, bootData);
        cpu.jump(100);
        cpu.execute();
    }
}
