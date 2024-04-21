let measurements = {
    weight: [150, 200, 250, 300],
    height: [60, 65, 70, 75]
}

console.log("initial measurements: ", measurements)

// let weightSum = measurements.weight.reduce((acc, cur) => acc + cur); //sum of all weight

// let doubleWeight = measurements.weight.map((weight) => weight * 2); //double the weight

// console.log("Sum of all weight: ", weightSum)
// console.log("Double the weight: ", doubleWeight)

//updatnig last value of weight and height
// measurements.weight[measurements.weight.length - 1] = 400;


// let iterating_over_all = measurements.weight.map((weight, index) => {
//     if (index === measurements.weight.length - 1) {
//         return 400;
//     }
//     return weight;
// });
// console.log("Iterating over all: ", iterating_over_all)

let newMeasurements = {
    weight: [...measurements.weight.slice(0, -1), 400],
    height: [...measurements.height.slice(-1)]
}

console.log("New measurements: ", newMeasurements)