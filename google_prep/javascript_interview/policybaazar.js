// //function
// const person1 = {
//   name: "John",
//   age: 30,
//   members: { father: "David", mother: "Ellie" },
// };

// const person2 = person1; //shallow copy

// const person3 = { ...person1 }; //will deep opy only first layer , make shallow copy of nested objects

// person2.name = "Jane";
// person3.members.father = "Ronnie";
// person3.name = "Sam";

// console.log(person1.name);
// console.log(person1.members.father);
// console.log(person2.members.father);
// console.log(person3.name);

//jane
//ronnie
//ronnie
//sam

// person2 is assigned directly to person1, so both reference the same object in memory.

// for spread operator
// person3 is created using the spread operator, which performs a shallow copy. This means:
// Top-level properties like name and age are copied by value.
// Nested objects like members are copied by reference, not by value

/* use this 
    const person3 = JSON.parse(JSON.stringify(person1));

    This approach creates a new object with all nested structures duplicated, ensuring that changes to person3 do not affect person1. However, be aware that this method has limitations:

    It doesn't copy functions, undefined, Infinity, NaN, or special objects like Date, RegExp, Map, Set, etc.

    It can be inefficient for large or complex objects.

    For more robust deep cloning, consider using libraries like Lodash's cloneDeep function.
*/

//--------------------------------2nd problem--------------------------
const obj = { a: 1, b: 2, c: { d: 4 } };

function updateObj(obj) {
  //passed as reference? yes
  obj.a = 5;
  obj.c = { e: 6 };
  console.log(obj.a, obj["c"]);
  obj = { c: 3 };
  console.log(obj.a, obj["c"]);
  obj.c["e"] = 8;
  console.log(obj.a, obj["c"]);
}

updateObj(obj);
console.log(JSON.stringify(obj));
