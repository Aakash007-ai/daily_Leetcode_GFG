package shreyansh_jain.chain_of_responsibility_design_pattern.logger;

public class DebugLogger extends LogProcessor {

    DebugLogger(LogProcessor nextLogProcessor){
        super(nextLogProcessor);
    }

    public void log(int level, String message){
        if(level == WARN){
            System.out.println("WARN : "+message);
        }else{
            super.log(level, message);
        }
    }
    
}
