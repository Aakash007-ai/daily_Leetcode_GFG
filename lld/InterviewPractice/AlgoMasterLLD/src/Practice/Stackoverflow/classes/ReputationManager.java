package Practice.Stackoverflow.classes;

import Practice.Stackoverflow.entities.User;
import Practice.Stackoverflow.interfaces.PostObserver;

public class ReputationManager implements PostObserver {
    private static final int QUESTION_UPVOTE_REP = 5;
    private static final int ANSWER_UPVOTE_REP = 10;
    private static final int ACCEPTED_ANSWER_REP = 15;
    private static final int DOWNVOTE_REP_PENALITY = -1;
    private static final int POST_DOWNVOTE_REP_PENALTY = -2;

    @Override
    public void onPostEvent(Event event) {
        User postAuthor = event.getTargetPost().getAuthor();
        switch (event.getEventType()) {
            case UPVOTE_QUESTION:
                postAuthor.updateReputation(QUESTION_UPVOTE_REP);
                break;
            case DOWNVOTE_QUESTION:
                postAuthor.updateReputation(DOWNVOTE_REP_PENALITY);
                event.getActor().updateReputation(POST_DOWNVOTE_REP_PENALTY);
                break;
            case UPVOTE_ANSWER:
                postAuthor.updateReputation(ANSWER_UPVOTE_REP);
                break;
            case DOWNVOTE_ANSWER:
                postAuthor.updateReputation(DOWNVOTE_REP_PENALITY);
                event.getActor().updateReputation(POST_DOWNVOTE_REP_PENALTY);
                break;
            case ACCEPT_ANSWER:
                postAuthor.updateReputation(ACCEPTED_ANSWER_REP);
                break;
            default:
                break;
        }
    }

}
