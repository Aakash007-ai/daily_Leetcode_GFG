package javaLang.BuilderDesignPattern;

import java.util.List;

public class Student {
    
    // whatever properties the student has , student build have same properties this is drwback due to code duplicacy
    int rollNumber;
    int age;
    String name;
    String fatherName;
    String motherName;
    List<String> subjects;

    public Student(StudentBuilder builder){//  here we are not creating multiple constructor , this is advantage
        this.rollNumber = builder.rollNumber;
        this.age = builder.age;
        this.name = builder.name;
        this.fatherName = builder.fatherName;
        this.motherName = builder.motherName;
        this.subjects = builder.subjects;
    }

    public String toString(){
        return ""+ "Roll Number: " + rollNumber + ", Age: " + age + ", Name: " + name + ", Father Name: " + fatherName + ", Mother Name: " + motherName + ", Subjects: " + subjects.get(0) + ", " + subjects.get(1) + ", " + subjects.get(2);
    }
}
