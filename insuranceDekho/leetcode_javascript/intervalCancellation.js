/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    fn(...args)
    let timerId= setInterval(() => {
        //return fn.call(...args) //after a time t fn will get called
        return fn(...args)
        
    }, t);

    return function(){
        //this function should cancel invokation of fn with argument 
        clearInterval(timerId)
    }
};

//fn is delayed so we have to wrap it in setTimeout with time t and store that timer id

const result = [];

const fn = (x) => x * 2;
const args = [4], t = 35, cancelTimeMs = 190;

const start = performance.now();

const log = (...argsArr) => {
    const diff = Math.floor(performance.now() - start);
    result.push({"time": diff, "returned": fn(...argsArr)});
}
    
const cancel = cancellable(log, args, t);

setTimeout(cancel, cancelTimeMs);

setTimeout(() => {
    console.log(result); // [
                        //     {"time":0,"returned":8},
                        //     {"time":35,"returned":8},
                        //     {"time":70,"returned":8},
                        //     {"time":105,"returned":8},
                        //     {"time":140,"returned":8},
                        //     {"time":175,"returned":8}
                        // ]
}, cancelTimeMs + t + 15)    
