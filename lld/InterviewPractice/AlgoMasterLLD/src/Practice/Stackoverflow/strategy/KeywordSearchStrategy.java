package Practice.Stackoverflow.strategy;

import java.util.List;
import java.util.stream.Collectors;

import Practice.Stackoverflow.entities.Content.Question;

public class KeywordSearchStrategy implements SearchStrategy {
    private final String keyword;

    public KeywordSearchStrategy(String keyword){
        this.keyword = keyword;
    }

    @Override
    public List<Question> filter(List<Question> questions) {
        return questions.stream()
                .filter(
                    q -> q.getTitle().toLowerCase().contains(keyword))
                    .collect(Collectors.toList());
    }


}
