/*
    Throttling is a technique to control the number of times a function is executed over a period of time

    It is used to ensure that the function is not called more than once in a given time frame
    ,even if the function is called multiple times

    e.g. while scrolling a page, we don't want to call the function that many times
    , so we use throttling to limit the number of times the function is called

*/

/*
    So, throttling is used to ensure function will call after some delay 
*/

function loadResults(){
    //expensive API calls and DOM rendering here
}

window.addEventListener("scroll",loadResults)

//since api calling is expensive, we don't want to call it multiple times
// but only once in a given time frame while doing scrolling

//optimized way
function loadResultsT(delay= 300){
    let lastResultLoaded = 0;
    const now= new Date().getTime();
    if(now - lastResultLoaded > 1000){
        //do expensive API call
        //and DOM rendering
        lastResultLoaded = now;
    }
}
window.addEventListener("scroll",loadResultsT)


//generic throttling function
function throttler(callback,delay=300){
    let lastCalled = 0;

    return function(...args){
        const now = new Date().getTime();
        if(now - lastCalled > delay){
            callback(...args);
            lastCalled = now;
        }
    }
}

const loadResultsThrottled = throttler(()=>{
    //now do expensive API call and DOM rendering
},3000)

window.addEventListener("scroll",loadResultsThrottled)