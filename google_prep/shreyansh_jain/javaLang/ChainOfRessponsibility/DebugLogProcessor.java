package javaLang.ChainOfRessponsibility;

public class DebugLogProcessor  extends LogProcessor{
    
    DebugLogProcessor(LogProcessor nextProcessor){
        super(nextProcessor);
    }

    public void log(String message, int level){
        if(level == DEBUG){
            System.out.println("Debug Log: " + message);
        } else {
            super.log(message, level); //we are saying call for next log function
        }
    }
}
