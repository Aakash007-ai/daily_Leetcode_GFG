package Practice.Stackoverflow.entities.Content;

import java.time.LocalDateTime;

import Practice.Stackoverflow.entities.User;

public abstract class Content {
    private final String id;
    private final User author;
    private final String content;
    protected final LocalDateTime creationTime;

    public Content(String id,User author, String content) {
        this.id = id;
        this.author = author;
        this.content = content;
        this.creationTime = LocalDateTime.now();
    }

    public User getAuthor() {
        return author;
    }

    public String getId() {
        return id;
    }

    public String getUserId() {
        return author.getId();
    }

    public String getContent() {
        return content;
    }
}
