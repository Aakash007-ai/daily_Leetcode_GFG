package mediator_design_pattern;

public class MediatorPatternExample {
    public static void main(String[] args){
        ChatRoomMediator chatRoom = new ChatRoom();
        User john = new User("John", chatRoom);
        User Wick = new User("Wick",chatRoom);

        john.sendMessage("Hi Wick");
        Wick.sendMessage("Hi John");
    }
}
