//setTimeout + closure

// function x(){
//     var a = 1;
//     //javascript does not wait here
//     setTimeout(function(){//this function forms a closure take reference of i
//         //it takes this fucntion and attaches the time
//         //as time run out it taken back and put in queue where event loop continue to 
//         //check the queue if it is empty then it will put the function in call stack

//         console.log(a);
//     }, 1000);
//     console.log("Namaaste Javascript");
// }
// x();

// x=closeure();  //check whether they follow same closurr
// y=closure();whether x and y follow same i or different


// function counter(){
//     //here i is a global variable
//     //and it is not block scope
//     //so closure formed by setTimeout will take reference of i not the value
//     for(var i=0; i<10; i++){
//         //var is stored in global scope and for every closure 
//         //it will take reference of i
//         setTimeout(function(){
//             console.log(i); //it refer to i
//         }, i*1000); //i*1000 is the time in ms
//     }
//     console.log("Start printing");
// }
// counter()


// function counter(){ //using let
//     for(let i=0; i<5; i++){
//         //for every iteration a new i is created
//         //as let is block scope and every time a new block is created
//         setTimeout(function(){
//             console.log(i); //it refer to i
//         }, i*1000); //i*1000 is the time in ms
//     }
//     console.log("Start printing");
// }
// counter()


//now just use var
//so we want a new copy of i for every closure
// function counter(){
//     for(var i=0; i<10; i++){
//         function count(){
//             setTimeout(function(){
//                 console.log(i); //it refer to i
//             }, i*1000); //i*1000 is the time in ms
//         }
//         close(i); //this will create a new copy of i for every closure
//         //as it is a new function and it will take i as a parameter
//         //and it will create a new copy of i for every closure
//     }
//     console.log("Start printing");
// }
// counter()



//check nested code execution callback with same new var inside e.g. a callback with same var variable
// var i=0;1
// setTimeout(function(){
//     var i=2;
//     console.log("timeout with i=2 ",i);
// }, 1000);

// setTimeout(function(){
//     var i=3;
//     console.log("timeout with i=2 ",i);
// }, 3000);

// setTimeout(function(){
//     var i=4;
//     console.log("timeout with i=4 ",i);
// }, 4000);

/////////////////////////////////////////////////////////////

// // crazy interview feat closure
// function outer (){
//     var a=10;
//     function inner(){
//         console.log(a);
//     }
//     var a=20;
//     return inner;
// }
// // console.log(a);
// outer()();
// console.log(a); //outer can go inner but inner definitaion can't go outer
// //as assume code execution of that fuction is over (get out of call stack)



// function outer(){
//     //var a=20;
//     function inner(){
//         console.log(a)
//     }
//     var a=20; //works as same way
//     return inner;
// }

// var close=outer();
// close()

//even if it is nested again then still inner function make closure with outer most function
// function outer(b){
//     //var a=20;
//     function inner(){
//         console.log(a,b)
//     }
//     var a=20; //works as same way
//     return inner;
// }

// var close=outer("hello");
// close()

// function outest(){
//     function outer(b){
//         //var a=20;
//         function inner(){
//             console.log(a,b,c)
//         }
//         var a=20; //works as same way
//         return inner;
//     }
//     var c=10;
//     return outer
// }
// var close=outest()("hello");
// close()


// //let naming conflict
// function outest(){
//     function outer(a){
//         //var a=20;
//         function inner(){
//             console.log(a,b,c)
//         }
//         let b=20; //works as same way
//         return inner;
//     }
//     let c=10;
//     return outer
// }
// let a=5;
// var close=outest()(a);
// close()

//closure used in function currying , module pattern, data hiding and encapsulation
//e.g. we have a counter and initialize to 0


// function counter(){
//     var count = 0;
//     count++;//here counter is a global variable and anyone can alter it
// }
// counter();
// console.log(count); //it will give error as count is not defined


// assigning same closure to multiple variable
// function counter(){
//     var count = 0;
//     return function(){
//         count++;
//         console.log(count);
//     }
// }
// var counter1 = counter();//it will create a closure
// counter1();//it remember the state of count
// counter1();
// var counter2 = counter(); //it will create a new closure
// counter2();//it will start from 1
// counter2();


//scalable counter
// function Counter(){ //good practice to start with capital letter (constructor function)
//     var count=0; //private variable as it is no accessible outside
//     this.incrementCounter = function(){
//         count++;
//         console.log(count);
//     }
//     this.decrementCounter = function(){
//         count--;
//         console.log(count);
//     }
// }

// var counter1 = new Counter(); //thi is a constructor function so we add new here
// counter1.incrementCounter();
// counter1.incrementCounter();
// counter1.decrementCounter();


//disadvantage of closure
//there will be over consumption of memory as it will store the state of variable
//so it will be a memory leak , as memory accumulates and not released and can freeze the browser
//so we can use garbage collection
//whenever there is no reference to a variable it will be garbage collected
//or we can use weak map

//but some advanced engine like v8 engine uses smart garbage collection
// it check whether the variable is used or not and then garbage collected
// memoization, maintaining state in async code

// if we add a breakpoint at console.log(x) then we find that only x is present in scope
// z which is not used anywhere is not present in scope
// function a(){
//     var x=0,z=10;
//     return function b(){
//         console.log(x);
//     }
// }

// var y=a();
// y();


///////////////////////////////////////////////

//first class function

// //function statement is also known as function declaration
// function x(){ console.log("I am x"); }

// //function expression
// var b = function y(){ console.log("I am y"); }
// b();

//difference between function statement and function expression is hoisting
//function statement is hoisted but function expression is not hoisted

//anonymous function (require a function name) is used 
//where we pass a function as an argument
//function (){ console.log("I am z");}

// var c=function (){
//     console.log("I am z");
// }

// //named function expression , xyz is not in outer scope created as local scope
// var c=function xyz(){ 
//     console.log("I am z"); 
//     console.log(xyz);
// }
// c()

 
// first class function
// as we can pass a function as an argument

// var b = function(xyz){
//     console.log("I am b");
//     console.log(xyz);
// }

// b(function xyz(){
//     console.log("I am xyz");
// })

// this ability to pass a function, return a function, assign a function to a variable
// this ability is first class function or first class citizens

//temporal dead zone , let and const are not hoisted they are in temporal dead zone
//or they have their block scope not in global scope

//////////////////////////////////////////////////////////////////////////////

//callback function ft closure

//what is callback function as function are first class citizens
//we can pass a function as an argument

// console.log("Start");
// setTimeout(function(){ //setTimeout take that callback function 
//     //and register it with timer and after that time 
//     //it will put it in queue
//     console.log("I am a callback function");
// }, 3000);
// console.log("End");

// function x(y){
//     console.log("x");
//     y();
// }

// x(function y(){
//     console.log("y");
// })

// document.getElementById('btn')
//     .addEventListener('click', function(){
//         console.log("Button clicked");
//     }
// )


//count how many times a function is called
// function count(){
//     var counter=0;
//     return function(){
//         counter++;
//         console.log("Button clicked",counter)
//     }

// }
// document.getElementById('btn')
//     .addEventListener('click', count()
// )


// function counter(){
//     var count=0;//we have attached a closure with callback function with scope of count
//     document.getElementById('btn').addEventListener("click",()=>{
//         count++;
//         console.log(count);
//     })
// }

// counter();//that scope will never be gonna garbage collected as it is attached to event listener

/////////////////////////////////////////////////////////////////////////////////////////////////////

//event loop

/* 
    call stack
    web api
    callback queue
    event loop
*/

/*
    javascript is single threaded language, it has 1 call stack present inside js engine
    every time a js function run, a global execution context is created
    and whole code pushed in call stack
    then all code run line by line (keep in mind memory heap is also present)
    if there is any function that execution context is pushed inside call stack
    and that function will get run and then popped out of call stack

    it quickly execute
    //whatif we want to run any code after 5 sec
    then we can't use it as it just execute the line by line, it doesn't have timer to wait

    so we have web api which is present in browser, timer is present in web api

    //web browser gives us lot of stuff to accesss (bluetooth, timer, Geo, Bluetooth , Camera)
    //so we have web api which is present in browser


    where normal callback queue is present
    e.g. settimeout callback function is put in callback queue
    and event loop is present in js engine
    it checks whether call stack is empty or not
    if it is empty then it will put the callback function in call stack

    addEventListner
    whenever code see addeventListner it attach the event with callback function with it
    so when we click on button it will put the callback function in callback queue
    and event loop will check whether call stack is empty or not

    why we need callback queue
    if user click multiple times innstant then it needs to respond to all the click
    one by one , so that every click is responded


    Fetch is another example of web api 
    it goes and return the data from server
    it keep a promise once i get data you run that function

    fetch('https://api.com').then(()=>{}).catch(()=>{})
        //this callback function will be waitng to get data from server
        once it get data it will put it in Microtask Queue
        and event loop will check whether call stack is empty or not

    Microtask has higher priority than callback queue
    Promise's callback,network call will go to the Microtask Queue
    +
    Mutation obserever(observe the dom that notifies the changes in dom)

    if that miccrotask queue create another callback function then it 
    still has higher priority than callback queue

    //try above point a promise with multiple callback function***********
*/

//after 3 that callback function put in queue and event loop will check the queue
//and if call stack is empty it will put the function in call stack

////////////////////////////////////////////////////////////////////////////////


//higher order function takes or return a function or both

// const radius = [3, 1, 2, 4];

// const calculateArea = function(radius){
//     const output = [];

//     for(let i=0;i< radius.length;i++){
//         output.push(Math.PI * radius[i] * radius[i]);
//     }
//     return output;
// }

// calculateCircumference = function(radius){
//     const output = [];

//     for(let i=0;i< radius.length;i++){
//         output.push(2 * Math.PI * radius[i]);
//     }
//     return output;
// }

// calculateDiameter = function(radius){
//     const output = [];

//     for(let i=0;i< radius.length;i++){
//         output.push(2 * radius[i]);
//     }
//     return output;
// }

//here we have a problem in our code as we are repeating the code, 
//we are iterating again and again only changes is calculation
// so we have to extract and pass array and logic to a fucntion and make a generic function


//functional programming reduce function interview perspective it is most important
// const radius = [3, 1, 2, 4];
// const calculate = function(radius,logic){
//     const output = [];
//     for(let i=0;i<radius.length;i++){
//         output.push(logic(radius[i]));
//     }
// }

// const area = function(radius){
//     return Math.PI * radius * radius;
// }

// // Array.prototype means allow every array to have this function
// Array.prototype.calculate = function(logic){
//     const output = [];
//     for(let i=0;i<this.length;i++){
//         output.push(logic(this[i]));
//     }
//     return output;
// }

// console.log(radius.calculate(area));