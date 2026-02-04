package Practice.SnakeAndLadder.entities;

public class Player {
    private String name;
    private int position;

    public Player(String name){
        this.name = name;
        this.position = 0;
    }

    public void setPosition(int num){
        this.position = num;
    }

    public String getName() {
        return name;
    }

    
    public int getPosition() {
        return position;
    }

}
