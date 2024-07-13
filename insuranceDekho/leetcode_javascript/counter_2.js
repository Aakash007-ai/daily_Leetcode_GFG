/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    const i = init,
    
    __proto__: {
    increment: function() {
        return ++init;
    }
    
    reset: function() {
        init=i;
        return init;
    }
    
    decrement:function(){
        return --init;
    }
    }
    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */