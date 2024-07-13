let counter: number; // here we explicitly specify a type for counter
let countr = 0; //here typescript infer the type of counter to be number
//it is equivalent to let counter :number =0;

//In same way
function setCounter(max = 100) {
  //here it infer type of max as number
  //similarly typescriptinfers the type of return
  return max++; //here return type is number infer by typescript
}

function increment(manx: number = 100): number {
  return manx;
}

let items = [1, 2, 3, 4, null]; //compiler interpret as array of number
let item = [0, 1, null, "Hi"]; //interpret as number | string |null

//when typescript cannot find it assume
//let arr = [new Date(),new RegExp('\d+')];

// Contextual typing
/* 
    typescript use locations of variables to infer their types.This mechanism is known as contextual typing

    document.addEventListner('click',function(event){
        console.log(event.button)
    })

    here typescript nows that event parameter is an instance of MouseEvent necause of click event
*/

//Type annotation we explicitly give type

/* 
    So, when to use type inference and anoontation
    in practice, we should always use type inferenceas much as possible

    type annotation
    when we declare a variable and assign a value later
    when ourvariable can't be inferred
    when a functio return the any type and we need to clarify value
*/
