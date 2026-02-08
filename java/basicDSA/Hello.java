public class Hello {
    public static void main(String[] args){
        System.out.println("Hello World");
        System.out.println("learning java for oops");
        John john = new John();
        john.name();

        Dog dog =new Dog();
        dog.bark();

        Vehicle v1 = new Vehicle();
        v1.horn();
        //v1.color = "red";
        v1.maxSpeed=23;
        System.out.println(v1.wheels);
        System.out.println(v1.maxSpeed);
        System.out.println(v1.color);
        System.out.println(v1.fuelCapacity);
    }
}
