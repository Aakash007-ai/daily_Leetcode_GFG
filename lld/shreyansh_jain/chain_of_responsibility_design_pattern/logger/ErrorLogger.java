package shreyansh_jain.chain_of_responsibility_design_pattern.logger;

public class ErrorLogger extends LogProcessor {
    public ErrorLogger(LogProcessor nextLogProcessor){
        super(nextLogProcessor);
    }

    public void log(int level, String message){
        if(level == ERROR){
            System.out.println("ERROR : "+ message);
        }else{
            super.log(level,message);
        }
    }
}
