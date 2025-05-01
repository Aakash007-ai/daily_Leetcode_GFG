package javaLang.ChainOfRessponsibility;

public class Main {
    public static void main(String[] args){
        LogProcessor logProcessor = new InfoLogProcessor(new DebugLogProcessor(null));

        logProcessor.log("log this event" ,LogProcessor.INFO);
    }
}
