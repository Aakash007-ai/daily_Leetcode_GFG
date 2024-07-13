let obj ={
    name:"John",
    place:"NYC",
}

function printName (country){
    console.log("First name is ",this.name ," and city is ", this.place , " ",country);
}

// let printName = () =>{ //why it print undefine instead of nameand city
//     console.log("First name is ",this.name ," and city is ", this.place);
// }

let printMyName = printName.bind(obj);// return a function bind to that object
// console.log()
printMyName("valhella")

Function.prototype.myBind =  function(...arg){
    let obj=this; //this here refer to the function to which it get attached
    console.log("this before returning a function",this)
    let arg1=arg.slice(1);
    return function(...arg2){
        obj.call(arg[0],[...arg1,...arg2]);
        console.log("this inside a returned function")
    }
}

let printMyName1 = printName.myBind(obj,"New Delhi")

printMyName1("Earth 162")