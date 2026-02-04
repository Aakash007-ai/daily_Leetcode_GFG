package Practice.LoggingFramework.strategies.appender;

import Practice.LoggingFramework.entities.LogMessage;
import Practice.LoggingFramework.strategies.formatter.LogFormatter;

public interface LogAppender {
    void append(LogMessage logMessage);
    void close();
    LogFormatter getFormatter();
    void setFormatter(LogFormatter formatter);
}
