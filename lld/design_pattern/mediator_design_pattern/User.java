package mediator_design_pattern;

public class User {
    private String name;
    private ChatRoomMediator chatRoomMediator;

    public User(String name, ChatRoomMediator chatRoomMediator){
        this.name = name;
        this.chatRoomMediator = chatRoomMediator;
    }

    public String getName(){
        return name;
    }

    public void sendMessage(String message){
        chatRoomMediator.showMessage(this, message);
    }
}
