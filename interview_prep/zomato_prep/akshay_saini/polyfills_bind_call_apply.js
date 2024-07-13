//here duplicatie the result of polyfills
let name = {
    firstName: "John",
    lastName : "WIck",
}

let printFullNAme = function(){
    console.log(this.firstnaem + ' ' + this.lastName);
}

name.printFullNAme(); //it successfully print the name

let printMyName = printFullNAme.bind(name);

//now replicate this

// mybind(){

// }

// let printMyName = printMyName.mybind(name3);

//every function in js has access to this bind
//and we want same for our function it should be visible to all
//and can be access

Function.prototype.mybind =function(...args){
    let oj=this
    return function(){
        Object.call(args[0])
    }
}

let cprintMyName = printMyName.mybind(name3);


