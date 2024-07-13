/*
    Type aliases allow you to create a new name for an existing type
*/

// type alias = existingType

type chars = string;
let message: chars;

type alphanumeric = string | number;
let input: alphanumeric;
input = 100;
input = "hello ";
// input = false    //gives error

/*
    the string literal types allow you to define a type that accepts only one specified string literal
*/

let click: "click";

click = "click";

//click ='dbclick' //it give error

// let mouseEvent : 'click' | 'dblclick' | 'mouseup'

// //if you use  string literal types in multiple place, they will be very verbose

// type MouseEvent = 'click' | 'dblclick' | 'mouseup' | 'mouseDown'

// let mouseEvent : MouseEvent
