package Practice.Stackoverflow.strategy;

import java.util.List;

import Practice.Stackoverflow.entities.Content.Question;

public interface SearchStrategy {
    List<Question> filter(List<Question> questions);
}
