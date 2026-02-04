package Algomaster.StackOverflow.dto;

import java.util.UUID;

import Algomaster.StackOverflow.dto.content.Content;

public class Comment extends Content{
    public Comment(String body, User author){
        super(UUID.randomUUID().toString(), body, author);
    }
}
