/**
 * @param {string} val
 * @return {Object}
 */


// var expect = function(val) {
//     return {
//         tobe: (arg)=>{
//             if(arg==val)
//                 return true
//             else throw new Error("Not Equal")
            
//         },
//         notToBe: (arg)=>{
//             if(arg!=val){
//                 return true;
//             }else throw new Error("Equal")
 
//         }
//     }
// };


var expect = function(val) {
    return {
        toBe: (val2) => {
            if (val !== val2) throw new Error("Not Equal");
            else return true;
        },
        notToBe: (val2) => {
            if (val === val2) throw new Error("Equal");
            else return true;
        }
    }
};





// var expect = function(val) {
//     return {
//         tobe: (arg)=>{
//             return arg==val ? true : new Error("Not Equal")
            
//         },
//         notToBe: (arg)=>{
//             return arg!=val? true : new Error("Not Equal")
//         }
//     }
// };







// var expect = function(val) {
//     return {
//         tobe: (arg)=>{
//             if(val==arg){
//                 return {value:true}
//             }
//             return {error:false}
            
//         },
//         notToBe: (arg)=>{
//             if(val!=arg){
//                 return {value:true}
//             }
//             return {error:false}
//         }
//     }
// };

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */