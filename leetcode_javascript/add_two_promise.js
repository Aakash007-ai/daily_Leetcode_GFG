/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */


var addTwoPromises = async function(promise1, promise2) {
    let result=0
    return new Promise.all([promise1,promise2]).then(values => values.reduce((acc,curr) => acc+curr))
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

// var addTwoPromises = async function(promise1, promise2) {
//     let result=0
//     return new Promise(function(resolve,reject){
//         try{
//             promise1.then(num=> result+=num);
//             promise2.then(num=> result += num)
//             resolve(result)
//         }catch(err){
//             reject
//         }
//    }) 
// };