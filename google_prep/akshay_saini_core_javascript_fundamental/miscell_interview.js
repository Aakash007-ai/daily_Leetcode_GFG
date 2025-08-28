// https://www.geeksforgeeks.org/pass-by-value-and-pass-by-reference-in-javascript/

// let obj = { name: "Ravi", age: 20, sex: { male: true } };

// function modify(o) {
//   o.name = "Arun";
//   o.age = 30;
//   o.sex = false;
//   console.log("Inside function: ", o);
//   o = { name: "world" };
//   console.log("After reassignment o will be", o);
// }

// modify(obj);
// console.log("Outside function: ", obj);

// https://medium.com/front-end-weekly/understanding-pass-by-value-and-pass-by-reference-in-javascript-8e2a0806b175

// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

// console.log("Try programiz.pro");
// const obj = { a: 1, b: 2, c:{d:4} };

// function updateObj(obj) { //passed as reference? yes
//   obj.a = 5;
//   obj = { c: 3 };

// }

// updateObj(obj);
// console.log(JSON.stringify(obj));

// const person1 = {
//   name: 'John',
//   age: 30,
//   members: { father: 'David', mother: 'Ellie' },
// };

// const person2 = person1;

// const person3 = { ...person1 };

// person2.name = 'Jane';
// person3.members.father = 'Ronnie';
// person3.name = 'Sam';

// //when it reference only nested object
// console.log(person1.name); // 'John'
// console.log(person1.members.father); // 'David'
// console.log(person2.members.father);// 'David'
// console.log(person3.name);// 'Sam'

// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

console.log("Try programiz.pro");

const person1 = {
  name: "John",
  age: 30,
  members: { father: "David", mother: "Ellie" },
};

const person2 = person1;

const person3 = { ...person1 };

person2.name = "Jane";
person3.members.father = "Ronnie";
person3.name = "Sam";

//when it reference only nested object
console.log(person1.name); // 'John'
console.log(person1.members.father); // 'David'
console.log(person2.members.father); // 'David'
console.log(person3.name); // 'Sam'

//when it reference string and number too
// console.log(person1.name);  'Jane'
// console.log(person1.members.father); 'David'
// console.log(person2.members.father); 'David'
// console.log(person3.name); 'Sam'

// const obj = { a: 1, b: 2 };

function updateObj(obj) {
  //passed as reference? yes
  obj.a = 5;
  obj = { c: 3 };
}

updateObj(obj);
console.log(obj);
{
  c: 3;
}

// type a = "abc" | "def"

// interface Baseesponse {
//     data: DTO,
//     msg :string,
//     id: number
// }

// interface b extend BaseResponse {

// }

// class A implement a{

// }

// Rotate a square matrix by 90 degrees

// const mat =
// [[1, 2, 3, 4],
// [5, 6, 7, 8],
// [9, 10, 11, 12],
// [13, 14, 15, 16]]

// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16

//  i=0
//  j=n-1

// for loop k=0-n/2
// i=0
// j=n-1
// k=0
// // first swap
// 13  2  3  1  swap mat[i][k] with mat[]
// 5  6  7  8
// 9  10 11 12
// 16 14 15 4

// //second swap
// 13  8  3  1
// 5  6  7  2     swap(same row)[col 0+1] with mat[col][row 0-->2]
// 9  10 11 12
// 16 14 15 4

// 13 9  5 1
// 14 10 6 2
// 15 11 7 3
// 16 12 8 4

// func rotateMatrix(mat){
//     let i=0
//     let j = mat.length-1;
//     while(i<j){
//         for(int k=i;k<j/2;k++){
//             //swap mat[row i][0->1,2] with mat[col 0,1,2][j];

//             //swap mat[][0] with mat[j][ 2,1,0]

//             //swap mat[row][0] with mat[n][0]
//         }
//     }
// }

// rotate matrix
