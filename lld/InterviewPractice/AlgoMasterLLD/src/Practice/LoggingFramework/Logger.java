package Practice.LoggingFramework;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import Practice.LoggingFramework.entities.LogMessage;
import Practice.LoggingFramework.enums.LogLevel;
import Practice.LoggingFramework.strategies.appender.LogAppender;

public class Logger {
    private final String name;
    private LogLevel level;
    private final Logger parent;
    private final List<LogAppender> appenders;
    private boolean additivity = true;

    Logger(String name, Logger parent){
        this.name = name;
        this.parent = parent;
        this.appenders = new CopyOnWriteArrayList<>();
    }

    public LogLevel getEffeectiveLevel(){
        for(Logger logger = this; logger != null;logger = logger.parent){
            LogLevel currentLevel = logger.level;
            if(currentLevel != null){
                return currentLevel;
            }
        }
        return LogLevel.DEBUG; // default root level
    }

    public void log(LogLevel messageLevel, String message){
        if(messageLevel.isGreaterOrEqual(messageLevel)){
            LogMessage logMessage = new LogMessage(messageLevel, this.name, message);
            callAppenders(logMessage);
        }
    }

    private void callAppenders(LogMessage logMessage) {
        if (!appenders.isEmpty()) {
            LogManager.getInstance().getProcessor().process(logMessage, this.appenders);
        }
        if (additivity && parent != null) {
            parent.callAppenders(logMessage);
        }
    }

    public void debug(String message) {
        log(LogLevel.DEBUG, message);
    }
    public void info(String message) {
        log(LogLevel.INFO, message);
    }
    public void warn(String message) {
        log(LogLevel.WARN, message);
    }
    public void error(String message) {
        log(LogLevel.ERROR, message);
    }
    public void fatal(String message) {
        log(LogLevel.FATAL, message);
    }

    // -----------Setters -----------------
    public void addAppender(LogAppender appender){
        appenders.add(appender);
    }

    public void setLevel(LogLevel level) {
        this.level = level;
    }

    public void setAdditivity(boolean additivity) {
        this.additivity = additivity;
    }

    //------------Getters ---------------

    public String getName() {
        return name;
    }

    public LogLevel getLevel() {
        return level;
    }

    public Logger getParent() {
        return parent;
    }

    public List<LogAppender> getAppenders() {
        return appenders;
    }

    public boolean isAdditivity() {
        return additivity;
    }


}
