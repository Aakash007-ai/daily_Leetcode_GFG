// setTimeout(() => {
//   console.log("Insurance Dekho timeout ");
// }, 0);

// console.log("Insurance Dekho");

// new Promise((res) => {
//   console.log("Promise dekho promise");
//   res();
// }).then(() => {
//   console.log("promise dekho resolve");
// });

// console.log("Insurance Dekho Promise resolved");

//-------------------------------------
console.log("First loop");
for (var i = 0; i < 3; i++) {
  setTimeout(() => {
    console.log("Ist loop ", i);
  }, 0);
}

console.log("New Loop");

for (let i = 0; i < 3; i++) {
  setTimeout(() => {
    console.log("2nd loop ", i);
  }, 0);
}

console.log("End of loop");
