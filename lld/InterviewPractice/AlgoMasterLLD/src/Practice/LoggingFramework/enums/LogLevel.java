package Practice.LoggingFramework.enums;

public enum LogLevel {
    DEBUG(1),
    INFO(2),
    WARN(3),
    ERROR(4),
    FATAL(5);

    private final int logLevel;

    LogLevel(int i) {
        this.logLevel = i;
    }

    public boolean isGreaterOrEqual(LogLevel other){
        return this.logLevel >= other.logLevel;
    }

}
