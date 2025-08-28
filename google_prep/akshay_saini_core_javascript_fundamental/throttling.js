//use for function optimization by
//e.g. machine gun, function will call initially and set atime to make it callable again after few second

let printMyName = function () {
  console.log("Print this name");
};

//return a throttled function
// let throttlingFn = function (func, limit = 200) {
//   let callFn = true;
//   return function () {
//     if (callFn) {
//       func();
//       callFn = false;
//       setTimeout(() => {
//         callFn = true;
//       }, limit);
//     }
//   };
// };

//
let throttlingFn = function (func, limit = 200) {
  let callFn = true;
  return function () {
    let context = this;
    args = arguments;
    if (callFn) {
      //   func();
      func.apply(context, args);
      callFn = false;
      setTimeout(() => {
        callFn = true;
      }, limit);
    }
  };
};
