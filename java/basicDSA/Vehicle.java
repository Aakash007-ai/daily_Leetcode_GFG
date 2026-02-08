/*  Class attributes
    by default attributes and methods of a class are public
    also we can set attributes by just calling its object.attributeName = abcdefgh
    by default constructor gives value 0 to int and null to string and 0.0 to double
*/

public class Vehicle {
    int maxSpeed;
    int wheels;
    String color;
    double fuelCapacity;

    void horn(){
        System.out.println("Horn ok please");
    }
}

/*
 * in general we don't follow above practice
 * we make attributes private
 */

// public class Vehicle {
//     private String color;

//     //getter
//     public String getColor(){
//         return color;
//     }

//     //setter
//     public void setColor(String c){
//         this.color = c;
//     }
// }
