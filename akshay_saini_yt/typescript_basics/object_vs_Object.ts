let employee: object;

employee = {
  firstName: "John",
  lastName: "Wick",
  age: 25,
  jobTitle: "Web Developer",
};

console.log(employee);

// employee = "Jane"; //will give error as we try to assign string to object
let employ: {
  firstName: string;
  lastName: string;
  age: number;
  jobTitle: string;
} = {
  firstName: "John",
  lastName: "Wick",
  age: 23,
  jobTitle: "SDE",
};

//above declaration does not give me autocomplete suggestion but below on give

/* the empty type*/
let vacant: {};
let vacancy: {} = {};
//we can access all properties and methods declared on the Object type, which is available on the object via prototype chain
console.log(vacancy.toString()); //[object Object]
