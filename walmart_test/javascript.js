eventloop;

// flex direction and flex wrap

//custom hooks

var a = 1;
function abc() {
  console.log(a);
  var a = 2;
  console.log(a);
}
abc();
console.log(a);

//resolve promise at one go

const p1 = Promise.resolve("Promise resolved");
const p2 = Promise.resolve("Promise rejected");

Promise.all([p1, p2]).catch((err) => console.log(err));
