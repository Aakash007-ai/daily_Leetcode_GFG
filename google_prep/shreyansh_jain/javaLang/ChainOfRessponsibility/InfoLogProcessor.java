package javaLang.ChainOfRessponsibility;

public class InfoLogProcessor extends LogProcessor {

    InfoLogProcessor(LogProcessor nextProcessor) {
        super(nextProcessor);
    }

    public void log(String message, int level){
        if(level == INFO){
            System.out.println("Info Log: " + message);
        } else {
            super.log(message, level); //we are saying call for next log function
        }
    }
    
}
