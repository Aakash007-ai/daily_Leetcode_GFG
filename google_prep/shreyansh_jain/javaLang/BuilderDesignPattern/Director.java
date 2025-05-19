package javaLang.BuilderDesignPattern;
// the hirrarchy goes like Student Builder return Student object, Director has Student Builder and it creates the student object

public class Director {// help in sequencing the steps to create the object
    StudentBuilder studentBuilder;

    Director(StudentBuilder studentBuilder){
        this.studentBuilder = studentBuilder;
    }

    public Student createStudent(){

        if(studentBuilder instanceof EngineeringStudentBuilder){
            return createEngineeringStudent();
        }else if(studentBuilder instanceof MBAStudentBuilder){
            return createMedicalStudent();
        }
        return null;
    }

    public Student createMedicalStudent(){
        return studentBuilder.setRollNumber(01)
                .setAge(20)
                .setName("Shreyansh Jain")
                .setFatherName("Rakesh Jain")
                .setMotherName("Suman Jain").setSubjects()
                .build(); //finally we return the obect of student
    }

    public Student createEngineeringStudent(){
        return studentBuilder.setRollNumber(01)
                .setAge(20)
                .setName("Shreyansh Jain")
                .setFatherName("Rakesh Jain")
                .setMotherName("Suman Jain")
                .build();
    }


    //     return studentBuilder.setRollNumber(01)
    //             .setAge(20)
    //             .setName("Shreyansh Jain")
    //             .setFatherName("Rakesh Jain")
    //             .setMotherName("Suman Jain")
    //             // .setBuilder()
    //             .build();
    // }
}
