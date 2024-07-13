/* 
    Functions

    function name(parameter:type,parameter:type....): returnType {} 
*/

function hello(val: number, val1: string): number {
  return 1;
}

function add(val: number, val1: number): number {
  return val + val1;
}

console.log(add(2, 4));

//option parameter function
//    function name(parameter:type,parameter?:type): returnType {}

function multiply(a: number, b: number, c?: number) {
  if (typeof c != "undefined") return a * b * c;
  return a * b;
}

// default parameter
//    function name(parameter:type,parameter = value): returnType {}

function applyDiscount(price: number, discount = 0.05) {
  return price * discount;
}

//default parameter and optional parameters
function applyDis(price: number, discount: number = 0.05): number {
  return 1;
}

function getDay(
  year: number = new Date().getFullYear(),
  month: number
): number {
  let day = 0;
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      day = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      day = 30;
      break;
    case 2:
      //leap year
      if ((year % 4 == 0 && !(year % 100 == 0)) || year % 400 == 0) day = 29;
      else day = 28;
      break;
    default:
      throw Error("invalid month");
  }
  return day;
}

let day = getDay(undefined, 2); //or pass nothing
console.log(day);

//rest parameter (a function has only one rest parameter, rest parameter appears last in parameter list, the type of the rest parameter is an array type)
//rest paramerter ...
function getTotal(...numbers: number[]): number {
  let total = 0;
  numbers.forEach((num) => (total += num));
  return total;
}
