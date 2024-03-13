//make a variable start a while loop based on that variable clear value of that varibale in settimeout
var a=5;
setTimeout(()=>{
    console.log('a value inside timeout',a)
    a=0; //this value is not setted
},1000)

while(a){
    console.log(a)
}
