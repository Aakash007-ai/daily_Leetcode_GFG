

///// this work different in strict and non strict mode
// "use strict"

// console.log("first window this",this) //it reflect instance of global object in global space


// function x(){
//     //inside a function this value depend on strict and non strict mode
//     console.log("inside x() a simple function ",this) //in strict it gives undefined
//     //in non strict it gives window
    
// }
// x();

//this inside non strict  mode(this substitution)
/*
    if value of this keyqord is undefined or null
    this keyword will be replaced with glbalObject only in non strict mode
*/

/*
    the value of this keyword is also defined by how the function is called at runtime binding(strict mode)
*/

//when we write a function as part of object it is called method
const obj = {
    a:10,
    x: function(){
        console.log("inside x under obj",this)
    },
    name:"John",
    printName: function(){
        console.log(this.name)
    }
}
//value of this become object inside object
obj.x() 

//call apply bind (sharing method)
// if we want to share method of an object 

// const student ={
//     name:"Wick"
//     //here we want printName to be reused
// }

// obj.printName.call(student) //here we pass our this to object method


//how does this behave this inside arraow fuinction
//arrow they don'thave this bind to them , the value of this  is lexical content of arrow function

const obj1 = {
    a:10,
    x:function (){
        console.log(this)
    }
}

obj1.x()


const obj2 = {
    a:10,
    x:() => {
        console.log(this)
    }
}

obj2.x()//it behave as enclosing lexical context


const obj3 = {
    a:10,
    x:function (){
        const  y = () => {
            console.log(this); //here this refer to enclosing lexical context
            //i.e. the object enclosing this
        }
        y()
        console.log(this)
    }
}

obj3.x()

//in dom it give the that element used inside that

//this im class and constructor