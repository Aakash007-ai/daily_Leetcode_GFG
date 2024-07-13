//performance optization, rate limitations
//in which scenario to use them

//debouncing 
//a search bar e.g. when you pause or have a gap in typing, scrolling or rate limiting
//debouncing, 

let counter = 0;
const getData = () => {
    console.log("feching data",++counter)
}

const debounce = function(fn,delay=1000){
    let timer;
    return function(){
        let context = this;
        args = arguments;
        clearTimeout(timer) //first clear previous
        //we want to call our function after some time
        timer = setTimeout(()=>{
            getData.apply(context,arguments)
        },delay);
    }
}
//we only want to call when user stop typing (or a some delay) 
const betterFunction = debounce(getData,700);
