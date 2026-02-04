package Algomaster.StackOverflow.interfaces;

import java.util.List;

import Algomaster.StackOverflow.dto.post.*;

public interface SearchStrategy {
    List<Question> filter(List<Question> questions);
}
