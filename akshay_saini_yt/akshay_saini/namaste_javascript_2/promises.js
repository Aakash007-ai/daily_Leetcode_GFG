////////////////////////////////////////////////////
//promises
/*
    Promises are used to handle asynchronous task in javascript
    3 state of promise
    pending when it is waiting 
    fulfilled
    rejected

    promise is a placeholder until we received a value

    in interview 
    promise is an object representing eventual completion or failure of an asynchronous operation
*/

// const user = fetch("https://reqres.in/api/users")
// console.log(user) //it return a promise in pending state

// // const promise = 
// const car = ["shoes","pants"]

// //callback hell
// createOrder(cart,function(orderId){
//     proceedToPayment(orderId, function(paymentInfop){
//         showOrderSummary(paymentInfop,function(){
//             updateWalletBalance();
//         })
//     })
// })

// //this is called promise chaining 
// createOrder(cart)
//     .then((orderId)=>proceedToPayment(orderId))
//     .then(paymentInfo=>shpwPaymentInfo())

// //we have to retrun some value so that we can receive it in next then

////////////////////////////////////////////////////////////////////////////
//promise
/*
    creating a promise
*/

// const cart = ["shoes","pants","kurta"]

// const promise = createorder(cart); //retrun a promise

// promise.then(function(){
//     proceedToPayment()
// })

//desired code we want to write


function validateCart(cart){
    return true;
}
 
function createOrder(cart){
    //new is used for every function constructor
    const pr= new Promise(function (resolve,reject){
        //reject(new Error("Cart is not valid"))

        if(!validateCart(cart)){
            reject(new Error("Cart is not valid"))
        }

        //logic for createorder
        const orderId = "12345";
        if(orderId){
            setTimeout(function(){
                resolve(orderId)
            },2000)
            
        }
    })
    return pr;
}


const procceedToPayment = function (cart){
    const pr= new Promise(function(resolve,reject){
        // reject(new Error("order id is not valid for payments"))
        if(!validateCart(cart)){
            reject(new Error("order id is not valid for payments"))
        }

        //logic for createorder
        const orderId = "12345";
        if(orderId){
            setTimeout(function(){
                resolve(orderId)
            },2000)
            
        }
    })
    return pr;
}

const promise = createOrder("123");

promise.then(function(orderId){//it register that callback function in local environment
    //and called once our promise getresolve and call stack will be empty
    console.log("cart created successfully",orderId)
    //if we want to return something to next then or out of this we just return
    return orderId;
})
.catch(error => {//
    console.log("error in cart",error)
})//
.then((orderId)=>{//this order id can come from catch or then  
    //we can add catch block here to catch error of above promise
    //procceed to nect statement
    console.log("handle next ",orderId)
    return procceedToPayment(orderId)
}).then(next => {
    console.log("payment done successfully")
})
.catch(error => {
    console.log("error in payments")
}).then(()=>{
    console.log("no matter what happened this will be called ")
})

console.log(promise) //if error came first it print here too the first promise

//try to throw 2 error and having a single catch()