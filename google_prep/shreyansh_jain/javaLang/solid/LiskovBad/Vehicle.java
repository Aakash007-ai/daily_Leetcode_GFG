package javaLang.solid.LiskovBad;
//Liskov substitution
// Liskov Substitution principle says that you could able to swap the object without breaking the code
/*
 * e.g. parentvp has 3 subclass ,c1,c2,c3 
 * then it should not break the below code
 * Parent parentObj =  new C1
 *                     new C2
 *                      new C3                      
 */
// if we have a parent class and a child class
// 


public class Vehicle {
    public Integer getNumberOfWheels(){
        return 2;
    }

    public Boolean hasEngine(){
        return true;
    }
}

