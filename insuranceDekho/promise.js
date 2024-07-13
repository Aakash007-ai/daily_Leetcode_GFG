

// // let p = new Promise((resolve,reject)=>{
// //     if(true){
// //         resolve("hello promise resolved")
// //     }
// //     else{
// //         reject("hello promise rejected")
// //     }
// // })

// // p.then(msg => {
// //     //
// // })

// //create a prototype of promise.all()


Promise.prototype.myAll = function(promises){
    
    return new Promise(()=>{
        let results = [];
        let counter = 0;
        promises.forEach(promise => {
            promise.then(result=>{
                results.push(result);
                counter++;
                resolve(result)
            }).catch(err => reject(err))
        })
    })
}

// //promise.all  if every promise get resolved then we get values in array, else throw error
// Promise.prototype.myAll = function(promises){
//     return new Promise((resolve,reject)=>{
//         let results = [];
//         let counter = 0;
//         promises.forEach((promise,index)=>{
//             promise.then((result)=>{
//                 results[index] = result;
//                 counter++;
//                 if(counter === promises.length){
//                     resolve(results);
//                 }
//             }).catch((err)=>{
//                 reject(err);
//             })
//         })
//     })
// }


// [
//     {roomNo: 1, bookingStartDate: '2022-04-24', bookingEndDate: '2022-04-27'},
//     {roomNo: 2, bookingStartDate: '2022-04-23', bookingEndDate: '2022-04-30'},
//     {roomNo: 1, bookingStartDate: '2022-04-29', bookingEndDate: '2022-04-30'},
// ]
// function isRoomAvailable(bookings, custStartDate, custEndDate, noOfRooms) {
//     for
//     // your code here
//     return; // true or false
// }


// arr = [1 -7] [6- 10] [15-19] 
// sort()
// [11-20]  obj= {a,b}\

//for i in bookings
//case 1 if obj is beyond date of i or obj date is more than i
// if(both condition true) we contiue to comapare 
// else fails already booked

// if for loop pass then we put it into list



//3 start date, end date  no. of rooms
// true if custromer requirement , n=100 ,
//customer says he has to book 


Promise.prototype.allSettled = function(promises){
    return new Promise((resolve,reject)=>{
        let results = [];
        let counter = 0;
        promises.forEach((promise,index)=>{
            promise.then((result)=>{
                results[index] = {status:"fulfilled",value:result};
                counter++;
                if(counter === promises.length){
                    resolve(results);
                }
            }).catch((err)=>{
                results[index] = {status:"rejected",reason:err};
                counter++;
                if(counter === promises.length){
                    resolve(results);
                }
            })
        })
    })
}


Promise.prototype.myRace = function(promises){
    return new Promise((resolve,reject)=>{
        promises.forEach((promise)=>{
            promise.then((result)=>{
                resolve(result)
            }).catch((err)=>{
                reject(err)
            })
        })
    })
}

Promise.prototype.myAny = function(promises){
    return new Promise((resolve,reject)=>{
        let counter = 0;
        promises.forEach((promise)=>{
            promise.then((result)=>{
                resolve(result)
            }).catch((err)=>{
                counter++;
                if(counter === promises.length){
                    reject("All promises rejected")
                }
            })
        })
    })
}
