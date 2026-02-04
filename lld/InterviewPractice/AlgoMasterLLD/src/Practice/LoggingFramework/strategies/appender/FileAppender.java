package Practice.LoggingFramework.strategies.appender;

import java.io.FileWriter;
import java.io.IOException;

import Practice.LoggingFramework.entities.LogMessage;
import Practice.LoggingFramework.strategies.formatter.LogFormatter;
import Practice.LoggingFramework.strategies.formatter.SimpleTextFormatter;

public class FileAppender implements LogAppender {
    private FileWriter writer;
    private LogFormatter formatter;
    
    public FileAppender(String path){
        this.formatter = new SimpleTextFormatter();
        try{
            this.writer = new FileWriter(path, true);
        }catch(Exception e){
            System.out.println("Failed to create writer for file logs, exception: " + e.getMessage());
        }

    }
    
    @Override
    public synchronized void append(LogMessage logMessage) {
        try {
            writer.write(formatter.format(logMessage) + "\n");
            writer.flush();
        } catch (IOException e) {
            System.out.println("Failed to write logs to file, exception: " + e.getMessage());
        }
    }

    @Override
    public void close() {
        try {
            writer.close();
        } catch (IOException e) {
            System.out.println("Failed to close logs file, exception: " + e.getMessage());
        }
    }

    @Override
    public LogFormatter getFormatter() {
        return this.formatter;
    }

    @Override
    public void setFormatter(LogFormatter formatter) {
        this.formatter = formatter;
    }
    
}
