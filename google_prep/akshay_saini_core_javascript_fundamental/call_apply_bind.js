// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
//   printName: () => {
//     console.log(this.firstName + " " + this.lastName);
//   },
// };

// name.printName();
//gives undefined because arrow functions do not have their own 'this' context
// as arrow function inherits 'this' from the parent scope which is inside that object
// this is {}  when the arrow function is called
// so it will not be able to access the properties of the object

// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
//   printName: () => {
//     console.log(lastName); //even we can't access lastname here
//   },
// };

// name.printName(); // Akshay Saini
//Todo why we can't access lastName here? or any other way to access it?
// because arrow function does not have its own 'this' context
// so it will not be able to access the properties of the object

// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
//   printName: function () {
//     console.log(this.firstName + " " + this.lastName);
//   },
// };

// name.printName(); // Akshay Saini

//call
/*
The call() method calls a function with a given this value and arguments provided individually.

call method bind an object to a function and calls that function with the object as this
*/

// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
//   // printName: function () {
//   //   console.log(this.firstName + " " + this.lastName);
//   // },
// };

// let printName = function () {
//   //here this will be the object we attach to this function
//   console.log(this.firstName + " " + this.lastName);
// };

// printName.call(name);

// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
//   // printName: function () {
//   //   console.log(this.firstName + " " + this.lastName);
//   // },
// };

// let printName = function (homeTown) {
//   //here this will be the object we attach to this function
//   console.log(this.firstName + " " + this.lastName + " from " + homeTown);
// };

// printName.call(name, "Delhi");

//apply
// The apply() method calls a function with a given this value, and arguments provided as an array (or an array-like object).

//e.g, in call we call like this
// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
// };

// let printName = function (homeTown, state) {
//   //here this will be the object we attach to this function
//   console.log(
//     this.firstName + " " + this.lastName + " from " + homeTown,
//     state
//   );
// };

// printName.call(name, "Panipat", "Haryana");

// but in apply we pass the arguments as an array
// let name = {
//   firstName: "Akshay",
//   lastName: "Saini",
// };

// let printName = function (homeTown, state) {
//   //here this will be the object we attach to this function
//   console.log(
//     this.firstName + " " + this.lastName + " from " + homeTown,
//     state
//   );
// };

// printName.apply(name, ["Panipat", "Haryana"]);

//bind
// The bind() method creates a new function that, when called, has its this keyword set to the provided value,
// with a given sequence of arguments preceding any provided when the new function is called.
let name = {
  firstName: "Akshay",
  lastName: "Saini",
};

let printName = function (homeTown, state) {
  //here this will be the object we attach to this function
  console.log(
    this.firstName + " " + this.lastName + " from " + homeTown,
    state
  );
};

let printMyName = printName.bind(name, "Panipat", "Haryana");

printMyName(); // Akshay Saini from Panipat Haryana

// difference between call and bind is that call calls the function immediately
// whereas bind returns a new function with the this keyword set to the provided value
