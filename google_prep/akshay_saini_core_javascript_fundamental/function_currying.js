//using bind method
let multiply = function (x, y) {
  console.log(x * y);
};

let multiplyByTwo = multiply.bind(this, 2);

multiplyByTwo(3);

//another way using closure
function multipy(x) {
  return function (y) {
    console.log(x * y);
  };
}

let multi2 = multipy(2);

multi2(3);
