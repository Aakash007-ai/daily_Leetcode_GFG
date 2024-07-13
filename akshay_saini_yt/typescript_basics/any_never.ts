/*
    sometimes, we may need to store a value in a variable but don't know its type
    in this case we use any here we allow it to pass theough compile-time check
*/

const json = `{"latitude":10.11,"longitude":12.12}`;

const currentLocation = JSON.parse(json);
console.log(currentLocation);

let result; //by default implicitly typscript assume any type

/* ------------------tsconfig.json
    to disable implict typing to the any type, change noImplicitAny option in tsconfig.json
*/

// let res: any;
// res = 10.123;
// console.log(res.toFixed());
// res.willExist(); //compiler will not raise issue as method may availabe at runtime

// let rs: object;
// rs = 10.123; //compiler will as raise issue
// rs.toFixed();

{
  /* never
    never type is a type that contains no values. So we cannot assign any value to a variable to a caraible with a never type

    we use never typpe to represent the return type of  a function that always throws an errror
*/
}
function raiseError(message: string): never {
  throw new Error(message);
}

// the return type of following function is inferred to the never type
function reject() {
  return raiseError("Rejected");
}

let infinite = function forever() {
  //by default type is never
  while (true) {
    console.log("hello");
  }
};

// function func(a:string | number):boolean{ //it give error as ins ome case return type is never
//     if(typeof a === "string")
//     {return true;}
//     else if(typeof a === "number"){
//         return false;
//     }
// }

function func(a: string | number): boolean {
  if (typeof a === "string") {
    return true;
  } else if (typeof a === "number") {
    return false;
  }
  return neverOccur();
}
let neverOccur = () => {
  throw new Error("Never");
};
