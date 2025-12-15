package facade_design_pattern;

public class CPU {
    public void freeze(){
        System.out.println("Freezing CPU...");
    }

    public void jump(long position){
        System.out.println("Jumping to position " + position);
    }

    public void execute(){
        System.out.println("Execting CPU commands");
    }
}
