package Practice.Stackoverflow.entities.Content;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.UUID;

import Practice.Stackoverflow.entities.Tag;
import Practice.Stackoverflow.entities.User;

public class Question extends Post {
    private final String title;
    private final Set<Tag> tags;
    private final List<Answer> answers = new ArrayList<>();
    private Answer acceptedAnswer;

    public Question(String title, String body, User author, Set<Tag> tags) {
        super(UUID.randomUUID().toString(), author, body);
        this.title = title;
        this.tags = tags;
    }

    public String getTitle() {
        return title;
    }

    public Set<Tag> getTags() {
        return tags;
    }

    public Answer getAcceptedAnswer() {
        return acceptedAnswer;
    }

    public void setAcceptedAnswer(Answer acceptedAnswer) {
        this.acceptedAnswer = acceptedAnswer;
    }

    public void addAnswer(Answer answer){
        this.answers.add(answer);
    }

    


}
