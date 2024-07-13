/*
    Promise Api
    Promise.all()
    Promise.allSettled
    Promise.race()
    Promise.any()
*/

/*
    Promise.all ----fail fast
    suppose if we have to make parallel api call and get the results
    it is used to handle multiple api call

    promise.all([p1,p2,p3])
    it take iterable or array and make parallel call of all 3
    e.g. p1(take 3s),p2(take 2s),p3(take 2s)

    all success (output of app promises will be in array)
    [val1,val2,val3] after 3s
    it wait for all of them to finish

    what happens after 1s any of them get
    as soon as any of them get rejected it throw the error
    Promise.all([p1,p2,p3]) //p2 get failed

    it will not wait for p1 or p3 , it just throw error after p2 time when it throw error
    not wait for other promises
*/

/*
    Promise.allSettled ---it wait for other to run then take action

    if all of them get successful after 3 sec we get same result
    but different in case of any one get failed

    Promise.allSettled([p1,p2,p3]) p1 3s , p2 1s , p3 2s
    //if p2 get failed it will wait for all promise to complete
    output will be 3 value irrespective of any one get failed
    val,error,error
*/

/*
    Promise.race([p1,p2,p3]) 
    person who finish first will be winner
    after 1sec it give me value of p2 promise
    
    it giev me value of first api

    whatif we get first error
    error will be thrown
*/

/*
    Promise.any([p1,p2,p3])
    it is same as Promise.race(it return first failed/success result)

    it return the first success result, if first one is rejected it wait for second one to get success

    what if everything fails, all of them get failed
    [it result aggregated result of all failed error]
    [err1,err2,err3] if all failed else val_success_of_first
*/


const p1 = new Promise(function(resolve,reject){
    setTimeout(()=>resolve("P1 success"),3000)
})

const p2 = new Promise(function(resolve,reject){
    setTimeout(()=>resolve("P1 success"),3000)
})

const p3 = new Promise(function(resolve,reject){
    setTimeout(()=>resolve("P1 success"),3000)
})

Promise.all([p1,p2,p3])
    .then(res=> console.log(res)) //return array if all get success
    .catch(err=>console.log(err)) // return error if any of them get failed

Promise.allSettled([p1,p2,p3]) //it will wait to collect the result and return their results
.then(res=> console.log(res)) //it will retrun array
    .catch(err=>console.log(err)) //try to fail; without catch statement
//return array of object [{status:"fulfilled/rejected"}]

Promise.race([p1,p2,p3]) //if result whether it is success or failure
    .then(res=> console.log(res))
    .catch(err=>console.log(err)) 

Promise.any([p1,p2,p3]) //first success
.then(res=> console.log(res)) 
    .catch(err=>console.log(err.errors)) //else if all failed then array of output
    //give AggregateError : All promise were rejected 



////////////////////////////////////////////////////////////////////////////

// async await  watch behind the scene part of video again
/*
    async keyword before function to create async function

    async function always return a promise
    either retrun a promise or
    suppose I return a value it take that return value and wrap it inside Promise and return vlue
*/