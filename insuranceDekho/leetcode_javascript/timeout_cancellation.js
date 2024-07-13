/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    let timerId= setTimeout(() => {
        //return fn.call(...args) //after a time t fn will get called
        return fn(...args)
        
    }, t);

    return function(){
        //this function should cancel invokation of fn with argument 
        clearTimeout(timerId)
    }
};

//fn is delayed so we have to wrap it in setTimeout with time t and store that timer id


const result = [];//

const fn = (x) => x * 5;//this function get called
const args = [2]
t = 20
cancelTimeMs = 50;

const start = performance.now();

const log = (...argsArr) => {
    const diff = Math.floor(performance.now() - start);
    result.push({"time": diff, "returned": fn(...argsArr)});
}
    
const cancel = cancellable(log, args, t);

const maxT = Math.max(t, cancelTimeMs);
        
setTimeout(cancel, cancelTimeMs);

setTimeout(() => {
    console.log(result); // [{"time":20,"returned":10}]
}, maxT + 15)
 