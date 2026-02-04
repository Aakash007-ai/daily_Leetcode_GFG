package Algomaster.StackOverflow.dto.content;

import java.time.LocalDateTime;

import Algomaster.StackOverflow.dto.User;

public abstract class Content {
    protected final String id;
    protected final String body;
    protected final User author;
    protected final LocalDateTime creationTimestamp;
    
    public String getId() {
        return id;
    }

    public String getBody() {
        return body;
    }

    public User getAuthor() {
        return author;
    }

    public Content(String id, String body, User author) {
        this.id = id;
        this.body = body;
        this.author = author;
        this.creationTimestamp = LocalDateTime.now();
    }
    
}

