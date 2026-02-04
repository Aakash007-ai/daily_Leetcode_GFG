package Algomaster.StackOverflow.dto.post;

import java.util.*;

import Algomaster.StackOverflow.dto.Event;
import Algomaster.StackOverflow.dto.Tag;
import Algomaster.StackOverflow.dto.User;
import Algomaster.StackOverflow.enums.EventType;

public class Question extends Post {
    private final String title;
    private final Set<Tag> tags;
    private final List<Answer> answers = new ArrayList<>();
    private Answer acceptedAnswer;

    public Question(String title, String body, User author, Set<Tag> tags) {
        super(UUID.randomUUID().toString(), body, author);
        this.title = title;
        this.tags = tags;
    }

    public void addAnswer(Answer answer) { this.answers.add(answer); }

    public synchronized void acceptAnswer(Answer answer) {
        if (!this.author.getId().equals(answer.getAuthor().getId()) && this.acceptedAnswer == null) {
            this.acceptedAnswer = answer;
            answer.setAccepted(true);
            notifyObservers(new Event(EventType.ACCEPT_ANSWER, answer.getAuthor(), answer));
        }
    }

    public String getTitle() { return title; }
    public Set<Tag> getTags() { return tags; }
    public List<Answer> getAnswers() { return answers; }
}