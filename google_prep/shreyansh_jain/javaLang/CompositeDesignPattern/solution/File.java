package javaLang.CompositeDesignPattern.solution;

public class File implements FileSystem {
    String fileName;

    File(String name){
        this.fileName = name;
    }
    
    public void ls(){
        System.out.println("File: " + fileName);
    }
}
