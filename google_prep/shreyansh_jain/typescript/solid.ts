/*
 solid 
*/

// S Single Responsibility
//  a class should have single reason to change
//bad appraoch
class UserService {
  registerUser(name: string, pssword: string) {
    console.log("registering user");
  }

  sendMail() {
    console.log("send mail");
  }
}

//Good apprach
class UserServic {
  registerUser(name: string, password: string) {
    console.log("registering user");
  }
}

class EmailService {
  sendEmail() {
    console.log("sending email");
  }
}

// O open for extension / closed for change
// a class should be extendable if a change has to be made, existing class should not get changed
// so that already tested code should be remain intact
// e.g. saveInvoice -> we can save it in db, local, or anywhere cloud S3
// so we should be able to extend the base class instead of extending it

// bad approach
class Invoice {
  calculateDiscount(customerType) {
    if (customerType === "regular") {
      return -20;
    } else if (customerType === "VIP") {
      return -50;
    }
  }
}
//Tomorrow there can be other type of user ,then again we have to modify this class

//good approach class based
// class DiscountStrategy {
//     getDiscount(){
//         return 0;
//     }
// }

// class RegularDiscount extends DiscountStrategy {
//     getDiscount(): number {
//         return -20;
//     }
// }

// class VipDiscount extends DiscountStrategy{
//     getDiscount(): number {
//         return -50;
//     }
// }

// class InvoiceService {
//     private discountStrategy : DiscountStrategy
//     constructor(discountStrategy : DiscountStrategy){
//         this.discountStrategy = discountStrategy;
//     }

//     calculateDiscount (){
//         return this.discountStrategy.getDiscount()
//     }
// }

// let obj=new InvoiceService(new VipDiscount())
// obj.calculateDiscount()

// interface based -> it can be like
interface SaveReceiptStrategy {
  saveReceipt: () => void;
}

class SaveToDB implements SaveReceiptStrategy {
  saveReceipt() {
    console.log("save to db");
  }
}

class SaveLocal implements SaveReceiptStrategy {
  saveReceipt() {
    console.log("save to local");
  }
}

class SaveReceipt {
  private saveStategy: SaveReceiptStrategy;
  constructor(saveStrategy: SaveReceiptStrategy) {
    this.saveStategy = saveStrategy;
  }

  saveReceipt() {
    return this.saveStategy.saveReceipt();
  }
}

// L Liskov Substitution
// if class B of sub type class A, then we should be able to replace object A with B, without breaking the behaviour of program
// subclass should extend the capability of parent class not narrow it down

//bad code engine specific
interface Bike {
  turnOnEngine: () => void;
  accelerater: () => void;
}

class MotorCycle implements Bike {
  private isEngineOn: boolean;
  private speed: number;

  turnOnEngine() {
    this.isEngineOn = true;
  }
  accelerater() {
    this.speed += 10;
  }
}

class Bicycle implements Bike {
  private isEngineOn: boolean;
  private speed: number;

  turnOnEngine() {
    this.isEngineOn = false;
  }

  accelerater() {
    this.speed += 10;
  }
}

//good code

interface Vehicle {
  accelerate: () => void;
}

class EngineVehicle implements Vehicle {
  turnonEngine: () => void;
  accelerate: () => void;
}

class MotorCycles extends EngineVehicle {}

class NonEngineVehicle implements Vehicle {
  accelerate: () => void;
}

let bike: Vehicle = new NonEngineVehicle();
bike.accelerate();

// now we get error at runtime when we try to a

// I interface segmented : interface should be such that client should not implement unnecessary function
interface RestaurantEmployee {
  // bad coed waiter does not cook food but have to add functionality of this
  washDishes: () => void;
  cookFood: () => void;
}

class Waiter implements RestaurantEmployee {
  washDishes: () => void;
  cookFood: () => void;
}

interface Employee {
  name: number;
  sayHi: () => void;
}

interface WaiterEmployee extends Employee {
  serveFood: () => void;
}

class WaiterEmployee implements WaiterEmployee {}
// here we have separated the interface of waiter and employee, so that we can implement only the required functionality

// D Dependency Inversion
// class should depend on abstractions not on concrete classes                                                                                                                                                                                        
// high level module should not depend on low level module, both should depend on abstractions