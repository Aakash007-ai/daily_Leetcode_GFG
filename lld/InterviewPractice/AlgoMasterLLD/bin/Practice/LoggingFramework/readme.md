The logging framework should support different log levels, such as DEBUG, INFO, WARNING, ERROR, and FATAL.
It should allow logging messages with a timestamp, log level, and message content.
The framework should support multiple output destinations, such as console, file, and database.
It should provide a configuration mechanism to set the log level and output destination.
The logging framework should be thread-safe to handle concurrent logging from multiple threads.
It should be extensible to accommodate new log levels and output destinations in the future.



-----------------
by following shreyansh chain, we have a chain of responsibility
where we create class of each log level and pass inside the constructor of other

according to that we have to pass output destination to reach class, in constructor, 
we pass obj.process(LOG_LEVEL, msg)

then destination also
-----------------------------

but we require to use methods like
console.log
console.info
etc



ability to append log to differnet destination