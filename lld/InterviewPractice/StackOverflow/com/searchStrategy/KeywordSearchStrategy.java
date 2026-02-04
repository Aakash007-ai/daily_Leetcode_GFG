package Algomaster.StackOverflow.searchStrategy;

import java.util.List;
import java.util.stream.Collectors;

import Algomaster.StackOverflow.dto.Tag;
import Algomaster.StackOverflow.dto.User;
import Algomaster.StackOverflow.dto.post.Question;
import Algomaster.StackOverflow.interfaces.SearchStrategy;

public class KeywordSearchStrategy implements SearchStrategy {
    private final String keyword;

    public KeywordSearchStrategy(String keyword) {
        this.keyword = keyword.toLowerCase();
    }

    @Override
    public List<Question> filter(List<Question> questions) {
        return questions.stream()
                .filter(q -> q.getTitle().toLowerCase().contains(keyword) ||
                        q.getBody().toLowerCase().contains(keyword))
                .collect(Collectors.toList());
    }
}

class TagSearchStrategy implements SearchStrategy {
    private final Tag tag;

    public TagSearchStrategy(Tag tag) {
        this.tag = tag;
    }

    @Override
    public List<Question> filter(List<Question> questions) {
        return questions.stream()
                .filter(q -> q.getTags().stream()
                        .anyMatch(t -> t.getName().equalsIgnoreCase(tag.getName())))
                .collect(Collectors.toList());
    }
}

class UserSearchStrategy implements SearchStrategy {
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