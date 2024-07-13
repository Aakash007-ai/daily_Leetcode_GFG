/**
 * @return {Function}
 */
var createHelloWorld = function() {
    let abc="Hello World"
    return function(...args) {
        console.log(abc)
    }
};


const f = createHelloWorld();
f(); // "Hello World"