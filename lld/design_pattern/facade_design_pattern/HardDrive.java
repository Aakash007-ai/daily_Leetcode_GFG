package facade_design_pattern;

public class HardDrive {
    public byte[] read(long lba, int size){
        System.out.println("Reading data from LBA "+ lba);
        return new byte[size];
    }
}
