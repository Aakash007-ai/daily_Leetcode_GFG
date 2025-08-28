// https://roadmap.sh/get-started
// https://roadmap.sh/questions/javascript
// https://roadmap.sh/backend?r=backend-beginner

// bind

let name = {
  firstName: "Aakash",
  lastName: "phogat",
};

let printName = function () {
  console.log(this.firstName + " " + this.lastName);
};

printName.bind(name)(); // Aakash phogat

//polyfill for bind
// myBind()
/*
   
*/

//if we keep any functino in protoyte then each type can access in that

//so my bind should return a function
// so return function
// also we want printName to be executed
// so instead of my bind pomints to this(printName method) refer to

Function.prototype.myBind = function (...args) {
  //that object which got bind
  let obj = this;
  let contextObj = args[0];
  let params = args.slice(1);

  return function (...params2) {
    // obj.call(contextObjm,...params);
    obj.apply(contextObj, [...params, ...params2]);
  };
};
