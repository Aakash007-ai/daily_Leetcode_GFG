package Algomaster.StackOverflow.dto.post;

import java.util.UUID;

import Algomaster.StackOverflow.dto.User;

public class Answer extends Post {
    private boolean isAccepted = false;

    public Answer(String body, User author) {
        super(UUID.randomUUID().toString(), body, author);
    }

    public void setAccepted(boolean accepted) {
        isAccepted = accepted;
    }

    public boolean isAccepted() { return isAccepted; }
}