package javaLang.BuilderDesignPattern;

public class MBAStudentBuilder extends StudentBuilder {
    
    @Override
    public StudentBuilder setSubjects(){
        // List<String> subs = new ArrayList<>();
        // subs.add("DSA");
        // subs.add("OS");
        // subs.add("DBMS");
        // this.subjects = subs;
        this.subjects.add("Marketing");
        this.subjects.add("Finance");
        this.subjects.add("HRM");
        return this;
    }
}
