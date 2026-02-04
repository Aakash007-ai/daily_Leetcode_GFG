package Practice.Stackoverflow.entities.Content;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.atomic.AtomicInteger;

import Practice.Stackoverflow.classes.Event;
import Practice.Stackoverflow.entities.User;
import Practice.Stackoverflow.enums.EventType;
import Practice.Stackoverflow.enums.VoteType;
import Practice.Stackoverflow.interfaces.PostObserver;

public abstract class Post extends Content {
    private final AtomicInteger voteCount = new AtomicInteger(0);
    private final Map<String, VoteType> voters = new ConcurrentHashMap<>();
    private final List<Comment> comments = new ArrayList<>();
    // private final List<PostObserver> observers = new ArrayList<>();

    public Post(String id,User author, String body){
        super(id, author, body);
    }

    public void addObserver(PostObserver observer){
        // this.observers.add(observer);
    }

    protected void notifyObservers(Event event){
    }

       public synchronized void vote(User user, VoteType voteType) {
        String userId = user.getId();
        if (voters.get(userId) == voteType)
            return; // Already voted

        int scoreChange = 0;
        if (voters.containsKey(userId)) { // User is changing their vote
            scoreChange = (voteType == VoteType.UPVOTE) ? 2 : -2;
        } else { // New vote
            scoreChange = (voteType == VoteType.UPVOTE) ? 1 : -1;
        }

        voters.put(userId, voteType);
        voteCount.addAndGet(scoreChange);

        EventType eventType = EventType.UPVOTE_QUESTION;

        if (this instanceof Question) {
            eventType = (voteType == VoteType.UPVOTE ? EventType.UPVOTE_QUESTION : EventType.DOWNVOTE_QUESTION);
        } else {
            eventType = (voteType == VoteType.UPVOTE ? EventType.UPVOTE_ANSWER : EventType.DOWNVOTE_ANSWER);
        }

        notifyObservers(new Event(eventType, user, this));
    }
}
