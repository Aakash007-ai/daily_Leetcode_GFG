package javaLang.BuilderDesignPattern;

public class Client {
    public static void main(String args[]){
        Director directorObj1 = new Director(new EngineeringStudentBuilder());
        Director directorObj2 = new Director(new MBAStudentBuilder());

        Student studentObj1 = directorObj1.createStudent();
        Student studentObj2 = directorObj2.createStudent();

        System.out.println(studentObj1.toString());
        System.out.println(studentObj2.toString());
    }
}
