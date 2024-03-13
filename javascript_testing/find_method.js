let arr = [{
    id:1,
    name: 'John',
    value : 100
},
{
    id:2,
    name: 'Doe',
    value : 200
},
{
    id:3,
    name: 'Smith',
    value : 300
}]
let result = arr.find((item) => item.id === 2);
console.log(result)