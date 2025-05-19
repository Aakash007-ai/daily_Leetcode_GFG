package javaLang.BuilderDesignPattern;

import java.util.List;

public abstract class StudentBuilder {
    // 2usagess of these properties , as student also has these parameterse as we have to pass them to student class
    int rollNumber;
    int age;
    String name;
    String fatherName;
    String motherName;
    List<String> subjects;

    //in builder we have steps, step by step we build the object
    public StudentBuilder setRollNumber(int rollNumber) {
        this.rollNumber = rollNumber;
        return this;
    }

    public StudentBuilder setAge(int age) {
        this.age = age;
        return this;
    }
    public StudentBuilder setName(String name) {
        this.name = name;
        return this;
    }
    public StudentBuilder setFatherName(String fatherName) {
        this.fatherName = fatherName;
        return this;
    }
    public StudentBuilder setMotherName(String motherName) {
        this.motherName = motherName;
        return this;
    }

    //just to differnetiate between engineering and medical student
    abstract public StudentBuilder setSubjects();

    public Student build(){
        return new Student(this);
    }
    // public abstract Student build();
}
