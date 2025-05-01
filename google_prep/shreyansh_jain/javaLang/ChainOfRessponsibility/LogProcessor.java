package javaLang.ChainOfRessponsibility;

public abstract class LogProcessor {
    public static int INFO = 1; //public static final int INFO = 1;
    public static int DEBUG = 2;
    public static int ERROR = 3;

    LogProcessor nextProcessor; // protected

    LogProcessor(LogProcessor nextProcessor){
        this.nextProcessor = nextProcessor;
    }

    public void log(String message, int level) {
        if(nextProcessor != null){
            nextProcessor.log(message, level);
        }
    }
}
