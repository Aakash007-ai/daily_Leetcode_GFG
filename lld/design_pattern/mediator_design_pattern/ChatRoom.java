package mediator_design_pattern;

public class ChatRoom implements ChatRoomMediator {

    @Override
    public void showMessage(User user, String message) {
        System.out.println(user.getName() + " : " + message);
    }
}
