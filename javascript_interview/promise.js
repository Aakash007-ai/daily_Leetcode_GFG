

let p = new Promise(function(resolve,reject){
    console.log("promise")
    resolve(1)
})

p.then(res=>{
    console.log("promise resolve",res)
})

console.log("hello")


// var addTwoPromises = async function(promise1, promise2) {
//     let result = 0
//     return new Promise(function(resolve,reject){
//         promise1.then(res=> result+=res)
//         promise2.then(res=> result+=res)

//         resolve(result);
//     })
// };


/**
 * @param {number} millis
 */
// async function sleep(millis) {
    
// }


async function sleep(milliseconds) {
	await new Promise(res => {
        let i=0;
        console.log("calling setTimeout")
        setTimeout(res(i), milliseconds)}
    )
}


let t = Date.now()
sleep(1000).then((i) => console.log(i, Date.now() - t)) // 100
 