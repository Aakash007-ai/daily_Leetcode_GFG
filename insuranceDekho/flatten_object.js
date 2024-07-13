
let user = { 
    name :{
        fullName : "Rahul Singh",
        age : 22,
        sex :undefined,
    },
    office : {
    Company: "GeeksforGeeks",
    Address: "Noida",
    contact: +91-999999999,
    mentor: {
        HTML: "GFG",
        CSS: "GFG",
        JavaScript: "GFG"
    }
}
}

// let finalObject = {}
 
let flattenObject = function(obj,parentKey="",finalObject={}){
    for(let key in obj){
        // console.log(typeof key,key, typeof obj[key])
        if(typeof obj[key] === "object"){
            // console.log("inside if",key, obj[key])
            flattenObject(obj[key],parentKey+key+"_",finalObject)
        }
        else{
            if(obj[key] === undefined){ //it separate out key which are undefined
                // console.log("inside else",key, obj[key])
                continue;
            }
            finalObject[parentKey+key] = obj[key]
        }
    }
    return finalObject;
}


console.log(flattenObject(user));

// console.log()






// let flattenFunc = (obj, parentKey = "", res = {}) => {
//     for (let key in obj) {
//         let newKey = parentKey + key;
//         if (typeof obj[key] === "object") {
//             flattenFunc(obj[key], newKey + ".", res);
//         } else {
//             res[newKey] = obj[key];
//         }
//     }
//     return res;
// }