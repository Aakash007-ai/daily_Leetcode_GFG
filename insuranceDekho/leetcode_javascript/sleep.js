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
 