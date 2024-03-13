var a=10;//so from where setimeout get a value we have define nothing

setTimeout(()=>{
    console.log('a value inside timeout',++a)
}, 3000)

setInterval(()=>{
    console.log(a);
    a++;
},2000)

setInterval(()=>{
    if(a>15){
        console.log('clearing interval')
        clearInterval()
    }
},1000)
console.log("normally a is ",a)