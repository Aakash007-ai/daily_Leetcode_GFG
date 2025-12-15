var n = 2;
function square(num) {
  var ans = num * num;
  return ans;
}

var square2 = square(n);
var square4 = square(4);

// in first phast of memory allocation it goes to first line
// and store n varaible as undefined then it go to function
// and store whole function

// then square 2 as undefined
// square4 as undefined

// in second pase code execution
// javascript run through whole program and go line by line
// here it check first line n==2

// now n is 2 is stored in memory code

// then it goes  to line 2 where it find that nothing to do here

// then it go to line 6  where we invoke a function
// so invoking a function means invoking or starting a brand new execution context

// again in code execution that function get invoked as

// Memory                  Code
// num:undefined
// ans undefuined

// COde execution  it check value of n in its parent context it is 2 then it passs the content

// and return ans . check ans value in memory

// and return the value of ans where the call stack

// same will be happen for next

// once javascript code gets run whole execution context get terminated

// to manage these execution context javascript has a call stack
// which start with global execution context
// and new context pushed into stack once it get inside stack and once these mini stack gets completed its control goes to global stack

// CAll Stack also known as

// execution context stack, program stack, control stack, runtime stack, machine stack

// CAll Stack maintain the order of execution of the execution context
