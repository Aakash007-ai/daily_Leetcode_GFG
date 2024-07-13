/*
    Class

    Javascript does not have a concept of class like other programming languages such as Java and C#
    in es5 we use a constructor function and prototype inf=heritance to create a class
*/

//function constructor
function Person(ssn, firstName, lastName) {
  this.ssn = ssn;
  this.firstName = firstName;
  this.lastName = lastName;
}

Person.prototype.getFullName = function () {
  return `${this.firstName} ${this.lastName}`;
};

let person = new Person("1", "John", "Wick");

console.log(person.getFullName());

//ES6 allow us to define a class which
class Perman {
  ssn: string;
  firstName: string;
  lastName: string;
  constructor(ssn, firstName, lastName) {
    this.ssn = ssn;
    this.firstName = firstName;
    this.lastName = lastName;
  }
}
