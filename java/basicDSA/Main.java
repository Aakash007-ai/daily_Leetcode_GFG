//Abstraction
/*
 * Data abstraction provides the outside world with only essential information, in a process of representing
 * essential information without including implementation details
*/

// polymorphism
/*
 * Polymorphism, which refers to idea of "having many forms", which occcurs when there is a hierarchy of class
 * related to each other through inheritance. A call to a member method will cause a different implementation 
 * to be executed, depending on the type of the object invoking the method.
 * Here is an example : Dog and Cat are classes that inherit Anmal class. Each class has its own implementation of the makeSiund method
 */
// class Animal {
//     public void makeSound(){
//         System.out.println("Grrr........");
//     }
// }

// class Dog extends Animal{
//     public void makeSound(){
//         System.out.println("Woof.....");
//     }

//     public void bark() {
//     }
// }

// class Cat extends Animal {
//     public void makeSound(){
//         System.out.println("Mew.....");
//     }
// }
// /*
//  * We have created two reference variable of type Animal and pointed them to cat and dog
//  */
// public class Main {
//     public static void main(String[] arg){
//         Animal a = new Dog();
//         Animal b = new Cat();

//         a.makeSound();
//         b.makeSound();
//     }
// }


// inheritance
// class A{
//     public A(){
//         System.out.println("class A constructor called");
//     }
// }

// class B extends A {
//     public B(){
//         System.out.println("class B constructor called");
//     }
// }
// public class Main {
//     public static void main(String[] args){
//         B obj = new B();
//     }
// }
