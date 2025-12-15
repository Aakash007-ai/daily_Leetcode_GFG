let nums = ["1", "2", "3", "4", "5"].map(parseInt);

nums.map;
console.log(nums); // Output: [1, NaN, NaN, NaN, NaN]

// Explanation: The map function passes three arguments to parseInt: the current element, the index, and the entire array. The second argument (index) is treated as the radix (base) for parseInt.
// For example:
// parseInt("1", 0) => 1 (base 10)
// parseInt("2", 1) => NaN (invalid base)
// parseInt("3", 2) => NaN (invalid base)
// parseInt("4", 3) => NaN (invalid base)
// parseInt("5", 4) => NaN (invalid base)
