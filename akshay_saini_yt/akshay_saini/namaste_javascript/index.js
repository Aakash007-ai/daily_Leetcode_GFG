/////////////////////////////////////////////////////////////////

//map filter reduce


// map is used to transform an array

//map [].map(callback function)

// Array.map(function(item, index, array){
//     //return new value
// })

const random = [1,2,3,4,4,5]

// console.log(random.map(item=>item*2))

//so by default map is a function that map array with given callback function
Array.prototype.myMap = function(logic){
    let output=[]
    for(let i=0;i<this.length;i++){
        output.push(logic(this[i]))
    }
    return output;
}

// console.log(random.myMap(i => i.toString(2)))
console.log(random.myMap( i => i.toString(2)))



//filter is used to filter out value from arrar

console.log(random.filter(i => i%2))

Array.prototype.myfilter = function(logic){
    let output=[];
    for(let i=0;i<this.length;i++){
        output.push(logic(this[i]));
    }
    return 
}

console.log()

//reduce is used to make calucation and consider prev output
//also its optional to send optional value
console.log(random.reduce((acc,curr)=>acc+curr,-15)) // or max(acc,curr)






//try custom reduce 







// var n=2;
// function square (num){
//     var ans = num * num;
//     return ans;
// }

// var square2 = square(n);
// var square4 = square(4);

// console.log(square2)
