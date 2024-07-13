// there are 3 things bind , call and apply
// bind is used to bind the context of the function to the object
// call is used to call the function with the context
// apply is used to call the function with the context and arguments

// polyfill for bind

function printName (name){
    console.log("Print my name--- "+ this.name)
}

// let name = "Saurabh" //bind function takes object as argument or array of objects
let printMyName = printName.bind({name:"Saurabh"})

// //since every function has access to bind so we are declaring 
// Function.prototype.myBind = function(...args){
//     // console.log("this inside myBind ",this)
//     // console.log("args ",args) array of objects passed to the function [{name:"Saurabh"}]
//     let obj=this //reference to the function printMyName1
//     return function(){
//         // console.log("this inside myBind ",this)
//         obj.call(args[0])//when there is single argument
//     }
// }

// let printMyName1 = printName.myBind({name:"Saurabh"}) //this will return a function
// printMyName1() //this will call the function

//since every function has access to bind so we are declaring 
Function.prototype.myBind = function(...args){
    // console.log("this inside myBind ",this)
    // console.log("args ",args) array of objects passed to the function [{name:"Saurabh"}]
    let obj=this //reference to the function printMyName1
    params = args.slice(1)//skip first element
    return function(){
        // console.log("this inside myBind ",this)
        //obj.call(args[0])//when there is single argument
        obj.apply(args[0],params)//when there are multiple arguments
    }//when we have to pass multiple arguments

}

let printMyName1 = printName.myBind({name:"Saurabh"}) //this will return a function
printMyName1() //this will call the function