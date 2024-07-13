
//throttling stop invoking a function for some delay after first invoking

// const wrapThrottled = function throttle(func, delay=1000){
//     //so we want to run first and start time if timer is on then skipp that
//     let invocation=true//
//     return function(){
//         if(invocation){
//             func();
//             invocation=false;
//             setTimeout(()=>{
//                 invocation=true; //after that time invoke function
//                 //make value false
//             },delay)
//         }
//     }
// }
//document.getElementById('btn').addEventListener("click",wrapThrottle(()=>{console.log("invocation of expensive call")}))


//now one more step towards it , by having function arguments
// const wrapThrottled = function throttle(func, delay=1000){
//     //so we want to run first and start time if timer is on then skipp that
//     let invocation=true//
//     return function(){
//         let context = this; //enclsoe
//         let arg= arguments;
//         if(invocation){
            
//             func.apply(context,arg); //we use apply methodlogy

//             invocation=false;
//             setTimeout(()=>{
//                 invocation=true; //after that time invoke function
//                 //make value false
//             },delay)
//         }
//     }
// }



//akshay code
const loggerFunc = () => {
  console.count("Throttled Function0----");
}

const throttle = (fn, limit) => {
  let flag = true;
  return function(){
    let context = this;
  
    let args = arguments;

    console.log(this,args)
    if(flag){
      fn.apply(args);
      flag = false;
      setTimeout(() => {
        flag=true;
      }, limit);
    }
  }
}

const betterLoggerFunction = throttle(loggerFunc, 1000);

window.addEventListener("btn",betterLoggerFunction);

// This is the normal Function without Throttling
//Check the console for the difference between the calls of Normal Function and the Throttled Function 
const normalFunc = () => {
  console.count("Normal Function");
}

window.addEventListener("resize",normalFunc);