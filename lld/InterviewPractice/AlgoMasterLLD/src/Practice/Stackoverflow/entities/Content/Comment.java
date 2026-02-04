package Practice.Stackoverflow.entities.Content;

import java.util.UUID;

import Practice.Stackoverflow.entities.User;

public class Comment extends Content {
    public Comment(String body, User author){
        super(UUID.randomUUID().toString(), author, body);
    }
}
