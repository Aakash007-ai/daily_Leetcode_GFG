package Practice.LoggingFramework.strategies.appender;

import Practice.LoggingFramework.entities.LogMessage;
import Practice.LoggingFramework.strategies.formatter.LogFormatter;
import Practice.LoggingFramework.strategies.formatter.SimpleTextFormatter;

public class ConsoleAppender implements LogAppender {
    LogFormatter formatter;

    public ConsoleAppender(){
        this.formatter = new SimpleTextFormatter();
    }

    @Override
    public void append(LogMessage logMessage) {
        System.out.println(formatter.format(logMessage));
    }

    @Override
    public void close() {}

    @Override
    public LogFormatter getFormatter() {
        return this.formatter;
    }

    @Override
    public void setFormatter(LogFormatter formatter) {
        this.formatter= formatter;
    }
    
}
