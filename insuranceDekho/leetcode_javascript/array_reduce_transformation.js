/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
// var reduce = function(nums, fn, init) {
    
// };


var reduce = function(arr, fn, initialVal) {
  let accumulator = initialVal;
  for (const index in arr) {
    accumulator = fn(accumulator, arr[index]);
  } 
  return accumulator;
};