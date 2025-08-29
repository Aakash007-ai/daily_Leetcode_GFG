package shreyansh_jain.chain_of_responsibility_design_pattern.logger;

public class InfoLogger extends LogProcessor {

    public InfoLogger(LogProcessor nextLogProcessor){
        super(nextLogProcessor);
    }

    public void log(int level, String message){
        if(level == INFO){
            System.out.println("INFO : " + message);
        }else{
            super.log(level, message);
        }
    }


}
