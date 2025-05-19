package javaLang.CompositeDesignPattern.solution;

// import javaLang.CompositeDesignPattern.solution.File;

public class Main {
    public static void main(String args[]){
        Directory movieDirectory =  new Directory("Movie");
        FileSystem border = new File("Border");
        
        movieDirectory.add(border);

        Directory comedyDirectory =  new Directory("Comedy");
        FileSystem hulchul = new File("Hulchul");

        movieDirectory.add(comedyDirectory);
        comedyDirectory.add(hulchul);

        movieDirectory.ls();

    }
}
