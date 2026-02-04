package Practice.LoggingFramework.strategies.formatter;

import Practice.LoggingFramework.entities.LogMessage;

public interface LogFormatter {
    String format(LogMessage logMessage);
}
