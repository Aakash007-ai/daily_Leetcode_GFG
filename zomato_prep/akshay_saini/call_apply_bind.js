let name = {
    firstName: "John",
    lastName : "WIck",
    printFullNAme : function(){
        console.log(this.firstnaem + ' ' + this.lastName);
    }
}

name.printFullNAme(); //it successfully print the name


let name2 = {
    firstName: "John",
    lastName : "WIck",
    printFullNAme : function(){
        console.log(this.firstnaem + ' ' + this.lastName);
    }
}

//not a good method writing this method again , so we do borrowing

let name3 = {
    firstName: "John",
    lastName : "WIck",
}
//function borrowing

name2.printFullNAme.call(name3);


//we can declare it as 
let printfullName =function(){
    console.log(this.firstnaem + ' ' + this.lastName);
}

printfullName.call(name3);

//apply work as same as call this just accept array as extra arguments
//we can declare it as 
let printfullName1 =function(city, state){
    console.log(this.firstnaem + ' ' + this.lastName + ' ' +city + ' ' +state);
}

printfullName1.call(name3,"city" ,"state");
printfullName1.apply(name3, ["city" ,"state"])

//bind work as same as call 

let printMyName= printfullName1.bind(name3);

printMyName();


