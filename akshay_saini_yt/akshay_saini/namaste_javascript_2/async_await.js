////////////////////////////////////////////////////////////////////////////

// async await  watch behind the scene part of video again
/*
    async keyword before function to create async function

    async function always return a promise
    either retrun a promise or
    suppose I return a value it take that return value and wrap it inside Promise and return vlue
*/

const p = new Promise(function(resolve,reject){
    resolve("Promise get resolved")
})
console.log("Hello")

// async function getData(){
//     //return p // it will not wrap that promise it jsut retun it
//     return "Hello" //it got wrap inside promise
// }

// const dataPromise = getData();

// dataPromise.then(res => {
//     console.log("this is return value ",res)
// })


async function handlePromise(){
    const val= await p; //await can only be used inside async function
    console.log(val);
}


handlePromise(); //it will return promise object