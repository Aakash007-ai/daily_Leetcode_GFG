package Practice.Stackoverflow.entities.Content;

import java.util.UUID;

import Practice.Stackoverflow.entities.User;

public class Answer extends Post{
    private boolean isAccepted;

    public Answer(String body, User author) {
        super(UUID.randomUUID().toString(), author, body);
     
    }

    public boolean isAccepted() {
        return isAccepted;
    }
    public void setAccepted(boolean isAccepted) {
        this.isAccepted = isAccepted;
    }

}
