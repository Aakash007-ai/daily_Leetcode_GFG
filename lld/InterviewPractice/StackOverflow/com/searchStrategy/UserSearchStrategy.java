package Algomaster.StackOverflow.searchStrategy;

import java.util.List;
import java.util.stream.Collectors;

import StackOverflow.dto.User;
import StackOverflow.dto.post.Question;
import StackOverflow.interfaces.SearchStrategy;

public class UserSearchStrategy implements SearchStrategy {
    private final User user;

    public UserSearchStrategy(User user) {
        this.user = user;
    }

    @Override
    public List<Question> filter(List<Question> questions) {
        return questions.stream()
                .filter(q -> q.getAuthor().getId().equals(user.getId()))
                .collect(Collectors.toList());
    }
}